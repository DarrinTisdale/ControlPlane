/*
 * LoggerAppDelegate.h
 *
 * BSD license follows (http://www.opensource.org/licenses/bsd-license.php)
 * 
 * Copyright (c) 2010 Florent Pillet <fpillet@gmail.com> All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of  source code  must retain  the above  copyright notice,
 * this list of  conditions and the following  disclaimer. Redistributions in
 * binary  form must  reproduce  the  above copyright  notice,  this list  of
 * conditions and the following disclaimer  in the documentation and/or other
 * materials  provided with  the distribution.  Neither the  name of  Florent
 * Pillet nor the names of its contributors may be used to endorse or promote
 * products  derived  from  this  software  without  specific  prior  written
 * permission.  THIS  SOFTWARE  IS  PROVIDED BY  THE  COPYRIGHT  HOLDERS  AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
 * NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A  PARTICULAR PURPOSE  ARE DISCLAIMED.  IN  NO EVENT  SHALL THE  COPYRIGHT
 * HOLDER OR  CONTRIBUTORS BE  LIABLE FOR  ANY DIRECT,  INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY,  OR CONSEQUENTIAL DAMAGES (INCLUDING,  BUT NOT LIMITED
 * TO, PROCUREMENT  OF SUBSTITUTE GOODS  OR SERVICES;  LOSS OF USE,  DATA, OR
 * PROFITS; OR  BUSINESS INTERRUPTION)  HOWEVER CAUSED AND  ON ANY  THEORY OF
 * LIABILITY,  WHETHER  IN CONTRACT,  STRICT  LIABILITY,  OR TORT  (INCLUDING
 * NEGLIGENCE  OR OTHERWISE)  ARISING  IN ANY  WAY  OUT OF  THE  USE OF  THIS
 * SOFTWARE,   EVEN  IF   ADVISED  OF   THE  POSSIBILITY   OF  SUCH   DAMAGE.
 * 
 */
#import <Cocoa/Cocoa.h>

@class LoggerConnection, LoggerStatusWindowController, LoggerPrefsWindowController;

@interface LoggerAppDelegate : NSObject
{
	CFArrayRef serverCerts;
	SecKeychainRef serverKeychain;

	NSMutableArray *transports;
	NSMutableArray *filterSets;
	NSArray *filtersSortDescriptors;
	LoggerStatusWindowController *statusController;
	LoggerPrefsWindowController *prefsController;
}

@property (nonatomic, readonly) CFArrayRef serverCerts;
@property (nonatomic, readonly) NSMutableArray *transports;
@property (nonatomic, readonly) NSMutableArray *filterSets;
@property (nonatomic, retain) NSArray *filtersSortDescriptors;
@property (nonatomic, readonly) LoggerStatusWindowController *statusController;

- (void)newConnection:(LoggerConnection *)aConnection;
- (NSMutableArray *)defaultFilters;
- (NSNumber *)nextUniqueFilterIdentifier:(NSArray *)filters;
- (void)saveFiltersDefinition;

- (IBAction)showPreferences:(id)sender;

- (BOOL)unlockAppKeychain;

@end

extern NSString * const kPrefPublishesBonjourService;
extern NSString * const kPrefHasDirectTCPIPResponder;
extern NSString * const kPrefDirectTCPIPResponderPort;
extern NSString * const kPrefBonjourServiceName;