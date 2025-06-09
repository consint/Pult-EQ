
#pragma once

#include <JuceHeader.h>

#include "src/AirWindows.h"

namespace airwindows::tube2_ns {
JUCE_BEGIN_IGNORE_WARNINGS_GCC_LIKE("-Wmultichar")
#include "src/Tube2.h"

#include "src/Tube2.cpp"
#include "src/Tube2Proc.cpp"
JUCE_END_IGNORE_WARNINGS_GCC_LIKE
}  // namespace airwindows::tube2_ns

namespace project {

using namespace juce;
using namespace hise;
using namespace scriptnode;

DECLARE_AIRWINDOWS_NODE(Tube2, tube2_ns);

}  // namespace project
