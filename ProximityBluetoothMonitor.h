//
//  ProximityBluetoothMonitor.h
//  Proximity
//
//  Created by Dominik Pich on 8/1/12.
//
//
#import <Cocoa/Cocoa.h>
//#import <IOBluetooth/IOBluetooth.h>
//#import <IOBluetoothUI/IOBluetoothUI.h>
#import <IOBluetoothUI/objc/IOBluetoothDeviceSelectorController.h>

//typedef enum _ProximityBluetoothStatus {
//	ProximityBluetoothStatusUndefined
//  ProximityBluetoothStatusInRange,
//	ProximityBluetoothStatusOutOfRange
//} ProximityBluetoothStatus;

NS_ENUM(NSInteger, ProximityBluetoothStatus) {
	ProximityBluetoothStatusUndefined,
    ProximityBluetoothStatusInRange,
    ProximityBluetoothStatusOutOfRange
} ProximityBluetoothStatus;

@class ProximityBluetoothMonitor;

@protocol ProximityBluetoothMonitorDelegate <NSObject>

- (void)proximityBluetoothMonitor:(ProximityBluetoothMonitor*)monitor foundDevice:(IOBluetoothDevice*)device;
- (void)proximityBluetoothMonitor:(ProximityBluetoothMonitor*)monitor lostDevice:(IOBluetoothDevice*)device;
- (void)setMenuIconInRange;
- (void)setMenuIconOutOfRange;

@end

@interface ProximityBluetoothMonitor : NSObject

@property(weak) id<ProximityBluetoothMonitorDelegate> delegate;
@property(nonatomic, assign) NSTimeInterval timeInterval;
@property(nonatomic, assign) NSInteger inRangeDetectionCount;
@property(nonatomic, assign) NSInteger outOfRangeDetectionCount;
@property(assign) BOOL requiredSignalStrength;
@property(retain) IOBluetoothDevice *device; // could be an array and statuses too

@property(readonly) enum ProximityBluetoothStatus priorStatus;
@property(readonly) enum ProximityBluetoothStatus status;
@property(readonly) enum ProximityBluetoothStatus iconStatus;

- (void)start;
- (void)stop;
- (void)refresh;

@end
