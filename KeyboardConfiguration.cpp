#include "KeyboardConfiguration.h"
#include "KeyboardDevice.h"
#include "KeyboardDescriptors.h"
#include "HIDTypes.h"

KeyboardConfiguration::KeyboardConfiguration() :
    BaseCompositeDeviceConfiguration(KEYBOARD_REPORT_ID),
    _useMediaKeys(false),
    _useSystemControl(false)
{
}

KeyboardConfiguration::KeyboardConfiguration(uint8_t reportId) :
    BaseCompositeDeviceConfiguration(reportId),
    _useMediaKeys(false),
    _useSystemControl(false)
{
}

uint8_t KeyboardConfiguration::getDeviceReportSize() const
{
    return sizeof(_keyboardHIDReportDescriptor);
}

size_t KeyboardConfiguration::makeDeviceReport(uint8_t* buffer, size_t bufferSize) const
{
    size_t hidDescriptorSize = sizeof(_keyboardHIDReportDescriptor);
    if(hidDescriptorSize < bufferSize){
        memcpy(buffer, _keyboardHIDReportDescriptor, hidDescriptorSize);
    } else {
        return -1;
    }

    if(_useMediaKeys){
        size_t mediaKeysHidDescriptorSize = sizeof(_mediakeysHIDReportDescriptor);
        if(hidDescriptorSize + mediaKeysHidDescriptorSize < bufferSize){
            memcpy(buffer + hidDescriptorSize, _mediakeysHIDReportDescriptor, mediaKeysHidDescriptorSize);
            hidDescriptorSize += mediaKeysHidDescriptorSize;
        } else {
            return -1;
        }
    }
    
    if(_useSystemControl){
        size_t systemControlHidDescriptorSize = sizeof(_systemControlHIDReportDescriptor);
        if(hidDescriptorSize + systemControlHidDescriptorSize < bufferSize){
            memcpy(buffer + hidDescriptorSize, _systemControlHIDReportDescriptor, systemControlHidDescriptorSize);
            hidDescriptorSize += systemControlHidDescriptorSize;
        } else {
            return -1;
        }
    }
    return hidDescriptorSize;
}

bool KeyboardConfiguration::getUseMediaKeys() const
{
    return _useMediaKeys;
}

bool KeyboardConfiguration::getUseSystemControl() const
{
    return _useSystemControl;
}

void KeyboardConfiguration::setUseMediaKeys(bool value)
{
    _useMediaKeys = value;
}
void KeyboardConfiguration::setUseSystemControl(bool value)
{
    _useSystemControl = value;
}