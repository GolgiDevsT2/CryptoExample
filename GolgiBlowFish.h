//
//  GolgiBlowFish.m
//
//  Copyright (c) 2013 Openmind Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Golgi.h"

@interface GolgiBlowFish : NSObject <GolgiCryptoImpl>
{
    int *P;
    int *sKey;
}

#if defined(GOLGI_BLOWFISH_SRC)
- (GolgiBlowFish *)initWithKeyData:(NSData *)key;
- (NSData *)encryptData:(NSData *)srcData;
- (NSData *)decryptData:(NSData *)srcData;
#endif

- (GolgiBlowFish *)initWithKey:(NSString *)key;

@end
