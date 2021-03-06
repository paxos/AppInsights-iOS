#import <Foundation/Foundation.h>
#import "MSAIHTTPOperation.h"

@class MSAIEnvelope;
@class MSAITelemetryContext;
@class MSAIAppClient;
@class MSAITelemetryContext;
@class MSAITelemetryData;
@class MSAISender;
@class MSAICrashData;

@interface MSAIChannel ()

///-----------------------------------------------------------------------------
/// @name Initialisation
///-----------------------------------------------------------------------------

+ (instancetype)sharedChannel;

///-----------------------------------------------------------------------------
/// @name Queue management
///-----------------------------------------------------------------------------

/**
 *  A queue which makes array operations thread safe.
 */
@property (nonatomic, strong) dispatch_queue_t dataItemsOperations;

/**
 *  An array for collecting data, which should be sent to the telemetry server.
 */
@property(nonatomic, strong) NSMutableArray *dataItemQueue;

/**
 *  Enqueue telemetry data (events, metrics, exceptions, traces) before processing it.
 *
 *  @param envelope the data object, which should be processed
 */
- (void)enqueueEnvelope:(MSAIEnvelope *)envelope;

/**
 *  Directly process telemetry data (crashs) without enqueuing it first.
 *
 *  @param envelope        the envelope object to process.
 *  @param completionBlock the block, which should be executed after the envelope has been persisted.
 */
- (void)processEnvelope:(MSAIEnvelope *)envelope withCompletionBlock: (void (^)(BOOL success)) completionBlock;

///-----------------------------------------------------------------------------
/// @name Batching
///-----------------------------------------------------------------------------

/*
 * Interval for sending data to the server in seconds.
 *
 * Default: 15
 */
@property (nonatomic, assign) NSInteger senderInterval;

/*
 * Threshold for sending data to the server. Default batch size for debugging is 150, for release
 * configuration, the batch size is 5.
 *
 * @warning: we advice to not set the batch size below 5 events.
 *
 * Default: 5
 */
@property (nonatomic, assign) NSInteger senderBatchSize;

/**
 *  A timer source which is used to flush the queue after a cretain time.
 */
@property (nonatomic, strong) dispatch_source_t timerSource;

/**
 *  Starts the timer.
 */
- (void)startTimer;

/**
 *  Stops the timer if currently running.
 */
- (void)invalidateTimer;

@end
