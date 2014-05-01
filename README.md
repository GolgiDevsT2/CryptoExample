# Example Crypto Module For Golgi
[Golgi](www.golgi.io) allows the developer to plugin their own cryptography modules to perform end-to-end encryption. 

This GitHub module contains an example implementation. It uses the [Blowfish](http://en.wikipedia.org/wiki/Blowfish_(cipher%29) symmetric-key block cipher to encode and decode payloads using a shared secret.

This is not the most secure or flexible implementation of end-to-end encryption, but it serves as an example of how the mechanism of user supplied crypto modules works in Golgi.

The most secure encryption would use some form of public key cryptography to encode with both the private key of the sender and the public key of the recipient. This is why the encrypt/decrypt methods are passed the destination and source respectively as extra parameters (not used by this implementation).

### Usage (Android/Java)

* Put GolgiBlowFish.java somewhere in your codebase (adjust the package definition accordingly).
* Instantiate an instance of GolgiBlowFish and plug it into the GolgiAPI before we are in a position to send or receive any payloads:
```
GolgiCryptoImpl crypto = GolgiBlowFish.createUsingKey("Super-Secret-Key-String");
if(crypto == null){
    // 
    // Zoikes, failed to instantiate GolgiBlowFish
    // This should never happen, throw an exception
    // and bail horribly if it does.
    // 
}
else{
    GolgiAPI.setCryptoImpl(crypto);
    //
    // That's it, all payloads will be sent encrypted
    // using the key we passed in above. If an encrypted
    // payload arrives, it will be passed to the GolgiBlowFish
    // instance for decryption where we assume it was encrypted
    // at the other end using the same key.
    //
}
```
### Usage (iOS)
* Add GolgiBlowFish.h and GolgiBlowFish.m somewhere in your project, then instantiate an instance and plug it into the GolgiAPI before we are in a position to send or receive any payloads:
```
GolgiBlowFish *crypto = [[GolgiBlowFish alloc] initWithKey:@"Super-Secret-Key-String"];
if(crypto == nil){
    //
    // Zoikes, failed to instantiate a GolgiBlowFish instance. 
    // This should never happen, exit horribly if it does.
    //
}
else{
    [GolgoAPI setCryptoImpl:crypto];
    //
    // That's it, all payloads will be sent encrypted
    // using the key we passed in above. If an encrypted
    // payload arrives, it will be passed to the GolgiBlowFish
    // instance for decryption where we assume it was encrypted
    // at the other end using the same key.
    //
}
```
