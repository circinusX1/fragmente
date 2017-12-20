
//
// a sample of cryptoc++ library public keys private keys encryption decryption
//
#include <iostream>
#include <sstream>
#include <string>
#include <cryptopp/rsa.h>
#include <cryptopp/dsa.h>
#include <cryptopp/hex.h>
#include <cryptopp/emsa2.h>
#include <cryptopp/osrng.h>
#include <cryptopp/pssr.h>
#include <cryptopp/whrlpool.h>


    using Signer   = CryptoPP::RSASS<CryptoPP::PSSR, CryptoPP::Whirlpool>::Signer;
    using Verifier = CryptoPP::RSASS<CryptoPP::PSSR, CryptoPP::Whirlpool>::Verifier;


    class RSAKeys
    {
    public:
        RSAKeys() = default;

       // copy c-tor
        RSAKeys(const RSAKeys& o){
            _priv = new CryptoPP::RSA::PrivateKey; _priv->Load(CryptoPP::StringSource(o.privstr(), true, new CryptoPP::HexDecoder()).Ref());
            _pub = new CryptoPP::RSA::PublicKey; _pub->Load(CryptoPP::StringSource(o.pubstr(), true, new CryptoPP::HexDecoder()).Ref());
        }

       // from hexa strings
        RSAKeys(const std::string& priv, const std::string& pub){
            _priv = new CryptoPP::RSA::PrivateKey; _priv->Load(CryptoPP::StringSource(priv, true, new CryptoPP::HexDecoder()).Ref());
            _pub = new CryptoPP::RSA::PublicKey; _pub->Load(CryptoPP::StringSource(pub, true, new CryptoPP::HexDecoder()).Ref());
        }

        //gen a hash
        void generate(const HashSha256& hash){
            generate((CryptoPP::byte*)(const uint8_t*)hash, sizeof(HashSha256));
        }

       // gen keypair
        void generate(CryptoPP::byte* hash, size_t sz)
        {
            CryptoPP::InvertibleRSAFunction params;
            CryptoPP::AutoSeededRandomPool rng;

            rng.IncorporateEntropy(hash, sz);
            params.GenerateRandomWithKeySize(rng, PBPR_KEY_SIZE);
            delete _priv;
            delete _pub;
            _priv = new CryptoPP::RSA::PrivateKey(params);
            _pub = new CryptoPP::RSA::PublicKey(params);

            std::cout << privstr() << std::endl<< std::endl;
            std::cout << pubstr() << std::endl;

        }
	// operator =
        const RSAKeys& operator=(const RSAKeys& o){
            delete _priv;
            delete _pub;
            _priv = new CryptoPP::RSA::PrivateKey; _priv->Load(CryptoPP::StringSource(o.privstr(), true, new CryptoPP::HexDecoder()).Ref());
            _pub = new CryptoPP::RSA::PublicKey; _pub->Load(CryptoPP::StringSource(o.pubstr(), true, new CryptoPP::HexDecoder()).Ref());
            return *this;
        }

       // return public key hex string readable
        std::string pubstr()const{
            std::string s;
            CryptoPP::StringSink  sink(s);
            _pub->DEREncode(sink);
            _key2string(s);
            return s;
        }

       // return pprivate key hex string readable
        std::string privstr()const{
            std::string s;
            CryptoPP::StringSink  sink(s);
            _priv->DEREncode(sink);
            _key2string(s);
            return s;
        }

	// encrypts a message
        std::string encrypt(const std::string& message)
        {
            std::string cipher;
            CryptoPP::RSAES_OAEP_SHA_Encryptor e(*_pub);
            CryptoPP::AutoSeededRandomPool rng;

            CryptoPP::StringSource ss1(message, true,
                new CryptoPP::PK_EncryptorFilter(rng, e,
                    new CryptoPP::HexEncoder(new CryptoPP::StringSink(cipher)))
            ); // StringSource
            return cipher;
        }

	// decrypts a message
        std::string decrypt(const std::string& message)
        {
            std::string recovered;
            CryptoPP::RSAES_OAEP_SHA_Decryptor d(*_priv);
            CryptoPP::AutoSeededRandomPool rng;

            CryptoPP::StringSource(message, true, new CryptoPP::HexDecoder(new CryptoPP::PK_DecryptorFilter(rng,
                      d, new CryptoPP::StringSink(recovered))));

            return recovered;
        }


    private:
        CryptoPP::RSA::PublicKey*    _pub = 0;
        CryptoPP::RSA::PrivateKey*   _priv = 0;

    };

