#!/bin/bash

#
# This file encrypts decrypts json.txt file 
#

openssl smime -encrypt -aes256 -in ./json.txt -binary -outform DER -out ./json.xxx newcert.pem
openssl smime -decrypt -in json.xxx -inform DER -inkey privkey.pem -out json.dec
