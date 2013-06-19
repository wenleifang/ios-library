/*
 Copyright 2009-2012 Urban Airship Inc. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// NSUserDefaultsKey for libUAirship verision >= v1.3.6
// Changing the key forces devices to update with UA at least once
// with new workflow. Previous key was "UAUserLastDeviceTokenKey", and
// is no longer used. 
#define kLastUpdatedDeviceTokenKey @"UAUserLastUpdatedDeviceTokenKey"

// Current dictionary keys
#define kUserUrlKey @"UAUserUrlKey"

@class UAHTTPRequest;

@interface UAUser()

// This device token represents the device token that is assigned to
// a user and is represented on the UA Servers. It may or may not be in sync
// with the device token on the UAPush object, which represents the token currently
// on the device.

// The current device token, stored in NSUserDefaults
- (NSString*)serverDeviceToken;

// Sets a new device token in NSUserDefaults. This has the side effect of lowercasing the string
// since strings returned from the server are upper case. 
- (void)setServerDeviceToken:(NSString*)token;

// Compares the currently persisted device token, which representes what is
// on the UA servers to the token associated with UAPush, which represents
// the token on device
- (BOOL)deviceTokenHasChanged;

//Device Token Change Listener
- (void)listenForDeviceTokenReg;
- (void)cancelListeningForDeviceToken;
- (void)updateDefaultDeviceToken;

@end

