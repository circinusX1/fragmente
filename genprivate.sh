#!/bin/bash

#
# generate key pairs without interraction
#

echo "generating private key"
openssl genrsa -out privkey.pem 2048

echo "signing provate key"
openssl req -new -key privkey.pem -out certreq.csr -subj "/C=RO/ST=AB/L=AB/O=None/OU=Department/CN=someweb.com"

echo "create a sign request"
openssl x509 -req -in certreq.csr -signkey privkey.pem -out newcert.pem
