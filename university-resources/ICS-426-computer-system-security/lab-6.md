# Lab 6: Creating Asymmetric Key Pairs

#### Overview
- In this exercise, you’ll create RSA and ECC key pairs using the OpenSSL command-line tool.

#### RSA Key Pair
- You can create a private RSA key using `openssl genrsa -out rsa-key.pem 2048`
    - Saved as a PEM file, 2048-bits
- You can create a public key based on the private key using `openssl rsa -in rsa-key.pem -pubout -out rsa-public.pem`
- View them using `cat`
    - They're encoded as Base64 ASCII data

#### Elliptic Curve Key Pair
- EC keys are a popular alternative to RSA
- You can view available curves using `openssl ecparam -list_curves`
- You can create a private key using the prime256v1 curve using `openssl ecparam -name prime256v1 -genkey -noout -out ecc-key.pem`
- You can create a public key from the private key using `openssl ec -in ecc-key.pem -pubout -out ecc-public.pem`
- View then using `cat`