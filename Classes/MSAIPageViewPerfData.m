#import "MSAIPageViewPerfData.h"
/// Data contract class for type PageViewPerfData.
@implementation MSAIPageViewPerfData
@synthesize envelopeTypeName = _envelopeTypeName;
@synthesize dataTypeName = _dataTypeName;

/// Initializes a new instance of the class.
- (instancetype)init {
    if (self = [super init]) {
        _envelopeTypeName = @"Microsoft.ApplicationInsights.PageViewPerf";
        _dataTypeName = @"PageViewPerfData";
    }
    return self;
}

///
/// Adds all members of this class to a dictionary
/// @param dictionary to which the members of this class will be added.
///
- (MSAIOrderedDictionary *)serializeToDictionary {
    MSAIOrderedDictionary *dict = [super serializeToDictionary];
    if (self.perfTotal != nil) {
        [dict setObject:self.perfTotal forKey:@"perfTotal"];
    }
    if (self.networkConnect != nil) {
        [dict setObject:self.networkConnect forKey:@"networkConnect"];
    }
    if (self.sentRequest != nil) {
        [dict setObject:self.sentRequest forKey:@"sentRequest"];
    }
    if (self.receivedResponse != nil) {
        [dict setObject:self.receivedResponse forKey:@"receivedResponse"];
    }
    if (self.domProcessing != nil) {
        [dict setObject:self.domProcessing forKey:@"domProcessing"];
    }
    return dict;
}

@end
