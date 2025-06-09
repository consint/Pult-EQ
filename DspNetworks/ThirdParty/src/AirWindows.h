#pragma once

#include <math.h>
#include <set>
#include <string>

#include <JuceHeader.h>

#define __audioeffect__
#define VstInt32             int32_t
#define AudioEffect          ::airwindows::AirWindowsBase
#define AudioEffectX         ::airwindows::AirWindowsBase
#define audioMasterCallback  ::airwindows::SampleRateCallback*
#define VstPlugCategory      int
#define kPlugCategEffect     1
#define kVstMaxProgNameLen   64
#define kVstMaxParamStrLen   64
#define kVstMaxProductStrLen 64
#define kVstMaxVendorStrLen  64
#define vst_strncpy          strncpy

namespace airwindows {
inline auto float2string(float f, char* text, int len) -> void
{
    int decimals = 0;
    if (std::fabs(f) >= 10.0) {
        decimals = 1;
    } else if (std::fabs(f) > 1.0) {
        decimals = 2;
    } else {
        decimals = 3;
    }

    juce::String str(f, decimals);
    str.copyToUTF8(text, (size_t)len);
}

inline auto int2string(float i, char* text, int len) -> void
{
    juce::String str(i);
    str.copyToUTF8(text, (size_t)len);
}

inline auto dB2string(float value, char* text, int maxLen) -> void
{
    if (value <= 0) {
        vst_strncpy(text, "-oo", (size_t)maxLen);
    } else {
        float2string((float)(20. * log10(value)), text, maxLen);
    }
}

struct SampleRateCallback
{
    SampleRateCallback() = default;

    auto getSampleRate() const noexcept -> double { return sampleRate; }

    double sampleRate{0.0};
};

class AirWindowsBase
{
public:
    AirWindowsBase(SampleRateCallback* c, int prog, int param)
        : numPrograms(prog)
        , numParams(param)
        , callback(c)
    {}

    int getNumInputs() { return numInputs; }

    int getNumOutputs() { return numOutputs; }

    int getNumParameters() { return numParams; }

    virtual bool getEffectName(char* name)                                                        = 0;
    virtual VstPlugCategory getPlugCategory()                                                     = 0;
    virtual bool getProductString(char* text)                                                     = 0;
    virtual bool getVendorString(char* text)                                                      = 0;
    virtual VstInt32 getVendorVersion()                                                           = 0;
    virtual void processReplacing(float** inputs, float** outputs, VstInt32 sampleFrames)         = 0;
    virtual void processDoubleReplacing(double** inputs, double** outputs, VstInt32 sampleFrames) = 0;
    virtual void getProgramName(char* name)                                                       = 0;
    virtual void setProgramName(char* name)                                                       = 0;

    virtual VstInt32 getChunk(void** data, bool isPreset)
    {
        juce::ignoreUnused(data, isPreset);
        return 0;
    };

    virtual VstInt32 setChunk(void* data, VstInt32 byteSize, bool isPreset)
    {
        juce::ignoreUnused(data, byteSize, isPreset);
        return 0;
    };

    virtual float getParameter(VstInt32 index)
    {
        juce::ignoreUnused(index);
        return 0;
    }

    virtual void setParameter(VstInt32 index, float value) { juce::ignoreUnused(index, value); }

    virtual void getParameterLabel(VstInt32 index, char* text) { juce::ignoreUnused(index, text); }

    virtual void getParameterName(VstInt32 index, char* text) { juce::ignoreUnused(index, text); }

    virtual void getParameterDisplay(VstInt32 index, char* text) { juce::ignoreUnused(index, text); }

    virtual VstInt32 canDo(char* text) = 0;

protected:
    void setNumInputs(int numIn) { numInputs = numIn; }

    void setNumOutputs(int numOut) { numOutputs = numOut; }

    void setUniqueID(int) {}

    void canProcessReplacing() {}

    void canDoubleReplacing() {}

    void programsAreChunks(bool) {}

    int numInputs = 0, numOutputs = 0, numPrograms = 0, numParams = 0;

    SampleRateCallback* callback;

    double getSampleRate() { return callback->getSampleRate(); }
};

}  // namespace airwindows

#define DECLARE_AIRWINDOWS_NODE(ClassName, Namespace)                                                \
    template<int NV>                                                                                 \
    struct ClassName final : public data::base                                                       \
    {                                                                                                \
        SNEX_NODE(ClassName);                                                                        \
        struct MetadataClass                                                                         \
        {                                                                                            \
            SN_NODE_ID(#ClassName);                                                                  \
        };                                                                                           \
                                                                                                     \
        static constexpr bool isModNode() { return false; };                                         \
        static constexpr bool isPolyphonic() { return NV > 1; };                                     \
        static constexpr bool hasTail() { return false; };                                           \
        static constexpr bool isSuspendedOnSilence() { return false; };                              \
        static constexpr int getFixChannelAmount() { return 2; };                                    \
        static constexpr int NumTables         = 0;                                                  \
        static constexpr int NumSliderPacks    = 0;                                                  \
        static constexpr int NumAudioFiles     = 0;                                                  \
        static constexpr int NumFilters        = 0;                                                  \
        static constexpr int NumDisplayBuffers = 0;                                                  \
        void prepare(PrepareSpecs specs)                                                             \
        {                                                                                            \
            _sampleRateSource.sampleRate = specs.sampleRate;                                         \
            _tmp.setSize(specs.numChannels, specs.blockSize);                                        \
        }                                                                                            \
        void reset() {}                                                                              \
        void handleHiseEvent(HiseEvent& e) {}                                                        \
        template<typename T>                                                                         \
        void process(T& data)                                                                        \
        {                                                                                            \
            auto buffer = juce::AudioBuffer<float>(                                                  \
                data.getRawChannelPointers(),                                                        \
                data.getNumChannels(),                                                               \
                data.getNumSamples()                                                                 \
            );                                                                                       \
            processInternal(buffer);                                                                 \
        }                                                                                            \
        template<typename T>                                                                         \
        void processFrame(T& data)                                                                   \
        {                                                                                            \
            auto** ptr = (float**)alloca(data.size() * sizeof(float*));                              \
            for (int i = 0; i < data.size(); i++) {                                                  \
                ptr[i] = data.begin() + i;                                                           \
            }                                                                                        \
            auto buffer = juce::AudioBuffer<float>(ptr, data.size(), 1);                             \
            processInternal(buffer);                                                                 \
        }                                                                                            \
        auto processInternal(juce::AudioBuffer<float>& buffer) -> void                               \
        {                                                                                            \
            _tmp.makeCopyOf(buffer);                                                                 \
            _engine.processReplacing(                                                                \
                _tmp.getArrayOfWritePointers(),                                                      \
                buffer.getArrayOfWritePointers(),                                                    \
                buffer.getNumSamples()                                                               \
            );                                                                                       \
        }                                                                                            \
        int handleModulation(double& value) { return 0; }                                            \
        void setExternalData(ExternalData const& data, int index) {}                                 \
        template<int P>                                                                              \
        void setParameter(double v)                                                                  \
        {                                                                                            \
            _engine.setParameter(P, static_cast<float>(v));                                          \
        }                                                                                            \
        void createParameters(ParameterDataList& data)                                               \
        {                                                                                            \
            for (auto i{0}; i < airwindows::Namespace::kNumParameters; ++i) {                        \
                char name[kVstMaxParamStrLen]{};                                                     \
                _engine.getParameterName(i, name);                                                   \
                auto parameter = parameter::data(name, {0.0, 1.0});                                  \
                registerCallback(parameter, i);                                                      \
                parameter.setDefaultValue(_engine.getParameter(i));                                  \
                data.add(std::move(parameter));                                                      \
            }                                                                                        \
        }                                                                                            \
                                                                                                     \
    private:                                                                                         \
        template<typename Param>                                                                     \
        auto registerCallback(Param& parameter, int i) -> void                                       \
        {                                                                                            \
            switch (i) {                                                                             \
                case 0: registerCallback<0>(parameter); break;                                       \
                case 1: registerCallback<1>(parameter); break;                                       \
                case 2: registerCallback<2>(parameter); break;                                       \
                case 3: registerCallback<3>(parameter); break;                                       \
                case 4: registerCallback<4>(parameter); break;                                       \
                case 5: registerCallback<5>(parameter); break;                                       \
                case 6: registerCallback<6>(parameter); break;                                       \
                case 7: registerCallback<7>(parameter); break;                                       \
                case 8: registerCallback<8>(parameter); break;                                       \
                case 9: registerCallback<9>(parameter); break;                                       \
                case 10: registerCallback<10>(parameter); break;                                     \
                case 11: registerCallback<11>(parameter); break;                                     \
                case 12: registerCallback<12>(parameter); break;                                     \
                case 13: registerCallback<13>(parameter); break;                                     \
                case 14: registerCallback<14>(parameter); break;                                     \
                case 15: registerCallback<15>(parameter); break;                                     \
                case 16: registerCallback<16>(parameter); break;                                     \
                case 17: registerCallback<17>(parameter); break;                                     \
                case 18: registerCallback<18>(parameter); break;                                     \
                case 19: registerCallback<19>(parameter); break;                                     \
                case 20: registerCallback<20>(parameter); break;                                     \
                case 21: registerCallback<21>(parameter); break;                                     \
                case 22: registerCallback<22>(parameter); break;                                     \
                case 23: registerCallback<23>(parameter); break;                                     \
                case 24: registerCallback<24>(parameter); break;                                     \
                default: break;                                                                      \
            }                                                                                        \
            jassert(false);                                                                          \
        }                                                                                            \
        airwindows::SampleRateCallback _sampleRateSource{};                                          \
        airwindows::Namespace::ClassName _engine{&_sampleRateSource};                                \
        juce::AudioBuffer<float> _tmp;                                                               \
    }
