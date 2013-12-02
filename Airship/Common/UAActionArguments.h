/*
 Copyright 2009-2013 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC``AS IS'' AND ANY EXPRESS OR
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

#import <Foundation/Foundation.h>

#define kPendingPushActionDefaultsKey @"com.urbanairship.action.pending"

/**
 * Represents a situation in which the application was launched from a push notification.
 */
extern NSString * const UASituationLaunchedFromPush;

/**
 * Represents a situation in which a push notification was received in the foreground.
 */
extern NSString * const UASituationForegroundPush;

/**
 * Represents a situation in which a push notification was received in the background.
 */
extern NSString * const UASituationBackgroundPush;

/**
 * Represents a situation in which the action was triggered from the application
 * being launched from the springboard.
 */
extern NSString * const UASituationLaunchedFromSpringBoard;

/**
 * Represents a situation in which the action was triggered from a
 * rich push message.
 */
extern NSString * const UASituationRichPushAction;

/**
 * Contains the arguments passed into an action during execution.
 */
@interface UAActionArguments : NSObject

/**
 * UAActionArguments factory method.
 *
 * @param value The value associated with the arguments.
 * @param situation The situation of the action.
 */
+ (instancetype)argumentsWithValue:(id)value withSituation:(NSString *)situation;

/**
 * Returns pending springboard actions and arguments.
 * 
 * @return An NSDictionary representing pending springboard actions by name, and their arguments.
 */
+ (NSDictionary *)pendingSpringBoardPushActionArguments;

/**
 * Adds a pending springboard action by name.
 *
 * @param name The name of the action.
 * @param value The value of the action's arguments.
 */
+ (void)addPendingSpringBoardAction:(NSString *)name value:(NSString *)value;

/**
 * Removes a pending springboard action by name.
 *
 * @param name The name of the action to remove.
 */
+ (void)removePendingSpringBoardAction:(NSString *)name;

/**
 * Clears all pending springboard action arguments.
 */
+ (void)clearSpringBoardActionArguments;

/**
 * Situation of the action
 */
@property(nonatomic, copy) NSString *situation;

/**
 * The value associated with the action
 */
@property(nonatomic, strong) id value;

/**
 * The name the action was invoked with.
 */
@property(nonatomic, copy) NSString *name;

@end