#pragma once

#include "Tube2.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace saturation_impl
{
// =============================| Node & Parameter type declarations |=============================

template <int NV>
using oversample_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, project::Tube2<NV>>, 
                                       core::gain<NV>>;

template <int NV>
using oversample_t = wrap::oversample<0, oversample_t_<NV>>;

namespace saturation_t_parameters
{
// Parameter list for saturation_impl::saturation_t -----------------------------------------------

template <int NV>
using Oversampling = parameter::plain<saturation_impl::oversample_t<NV>, 
                                      0>;
template <int NV>
using Tube = parameter::plain<project::Tube2<NV>, 1>;
template <int NV>
using Gain = parameter::plain<core::gain<NV>, 0>;
template <int NV>
using Filter = parameter::plain<saturation_impl::oversample_t<NV>, 
                                1>;
template <int NV>
using saturation_t_plist = parameter::list<Oversampling<NV>, 
                                           Tube<NV>, 
                                           Gain<NV>, 
                                           Filter<NV>>;
}

template <int NV>
using saturation_t_ = container::chain<saturation_t_parameters::saturation_t_plist<NV>, 
                                       wrap::fix<2, oversample_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public saturation_impl::saturation_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(saturation);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(66)
		{
			0x005B, 0x0000, 0x4F00, 0x6576, 0x7372, 0x6D61, 0x6C70, 0x6E69, 
            0x0067, 0x0000, 0x0000, 0x0000, 0x4080, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x015B, 0x0000, 0x5400, 0x6275, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x025B, 0x0000, 0x4700, 0x6961, 0x006E, 0x0000, 
            0xC2C8, 0x0000, 0x0000, 0x0000, 0x0000, 0x833E, 0x40AD, 0xCCCD, 
            0x3DCC, 0x035B, 0x0000, 0x4600, 0x6C69, 0x6574, 0x0072, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000
		};
	};
	
	instance()
	{
		// Node References ------------------------------------------------------------------------
		
		auto& oversample = this->getT(0);    // saturation_impl::oversample_t<NV>
		auto& Tube2 = this->getT(0).getT(0); // project::Tube2<NV>
		auto& gain = this->getT(0).getT(1);  // core::gain<NV>
		
		// Parameter Connections ------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, oversample); // Oversampling -> oversample::Oversampling
		
		this->getParameterT(1).connectT(0, Tube2); // Tube -> Tube2::Tube
		
		this->getParameterT(2).connectT(0, gain); // Gain -> gain::Gain
		
		this->getParameterT(3).connectT(0, oversample); // Filter -> oversample::FilterType
		
		// Default Values -------------------------------------------------------------------------
		
		; // oversample::Oversampling is automated
		; // oversample::FilterType is automated
		
		Tube2.setParameterT(0, 0.5); // project::Tube2::Input
		;                            // Tube2::Tube is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 1.);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using saturation = wrap::node<saturation_impl::instance<NV>>;
}


