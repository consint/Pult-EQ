#pragma once

#include "pultecFaust.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace pultstereo_impl
{
// ==========================| Node & Parameter type declarations |==========================

namespace pultstereo_t_parameters
{
// Parameter list for pultstereo_impl::pultstereo_t -----------------------------------------

DECLARE_PARAMETER_RANGE_STEP(BoostLow_InputRange, 
                             0., 
                             20., 
                             1.);
DECLARE_PARAMETER_RANGE_SKEW(BoostLow_0Range, 
                             0., 
                             20., 
                             0.8);

template <int NV>
using BoostLow_0 = parameter::from0To1<project::pultecFaust<NV>, 
                                       0, 
                                       BoostLow_0Range>;

template <int NV>
using BoostLow = parameter::chain<BoostLow_InputRange, BoostLow_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(AttenLow_InputRange, 
                             0., 
                             130., 
                             1.);
DECLARE_PARAMETER_RANGE_SKEW(AttenLow_0Range, 
                             0., 
                             130., 
                             3.5);

template <int NV>
using AttenLow_0 = parameter::from0To1<project::pultecFaust<NV>, 
                                       1, 
                                       AttenLow_0Range>;

template <int NV>
using AttenLow = parameter::chain<AttenLow_InputRange, AttenLow_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Adjust_InputRange, 
                             0., 
                             150., 
                             1.);
DECLARE_PARAMETER_RANGE_SKEW(Adjust_0Range, 
                             0., 
                             150., 
                             4.);

template <int NV>
using Adjust_0 = parameter::from0To1<project::pultecFaust<NV>, 
                                     3, 
                                     Adjust_0Range>;

template <int NV>
using Adjust = parameter::chain<Adjust_InputRange, Adjust_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(BoostHi_InputRange, 
                             0., 
                             93., 
                             1.);
DECLARE_PARAMETER_RANGE_SKEW(BoostHi_0Range, 
                             0., 
                             93., 
                             5.);

template <int NV>
using BoostHi_0 = parameter::from0To1<project::pultecFaust<NV>, 
                                      4, 
                                      BoostHi_0Range>;

template <int NV>
using BoostHi = parameter::chain<BoostHi_InputRange, BoostHi_0<NV>>;

template <int NV>
using CPSLow = parameter::plain<project::pultecFaust<NV>, 
                                2>;
template <int NV>
using AttenHi = parameter::plain<project::pultecFaust<NV>, 
                                 5>;
template <int NV>
using CPSHi = parameter::plain<project::pultecFaust<NV>, 
                               6>;
template <int NV>
using HiCutF = parameter::plain<project::pultecFaust<NV>, 
                                7>;
template <int NV>
using pultstereo_t_plist = parameter::list<BoostLow<NV>, 
                                           AttenLow<NV>, 
                                           CPSLow<NV>, 
                                           Adjust<NV>, 
                                           BoostHi<NV>, 
                                           AttenHi<NV>, 
                                           CPSHi<NV>, 
                                           HiCutF<NV>>;
}

template <int NV>
using pultstereo_t_ = container::chain<pultstereo_t_parameters::pultstereo_t_plist<NV>, 
                                       wrap::fix<2, project::pultecFaust<NV>>, 
                                       math::inv<NV>, 
                                       core::gain<NV>>;

// ==============================| Root node initialiser class |==============================

template <int NV> struct instance: public pultstereo_impl::pultstereo_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(pultstereo);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(132)
		{
			0x005B, 0x0000, 0x4200, 0x6F6F, 0x7473, 0x6F4C, 0x0077, 0x0000, 
            0x0000, 0x0000, 0x41A0, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x015B, 0x0000, 0x4100, 0x7474, 0x6E65, 0x6F4C, 0x0077, 
            0x0000, 0x0000, 0x0000, 0x4302, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x025B, 0x0000, 0x4300, 0x5350, 0x6F4C, 0x0077, 
            0x0000, 0x0000, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x035B, 0x0000, 0x4100, 0x6A64, 0x7375, 0x0074, 
            0x0000, 0x0000, 0x0000, 0x4316, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x045B, 0x0000, 0x4200, 0x6F6F, 0x7473, 0x6948, 
            0x0000, 0x0000, 0x0000, 0xBA00, 0x0042, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0005, 0x0000, 0x7441, 0x6574, 0x486E, 
            0x0069, 0x0000, 0x0000, 0x0000, 0x41F0, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x065B, 0x0000, 0x4300, 0x5350, 0x6948, 
            0x0000, 0x0000, 0x0000, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0007, 0x0000, 0x6948, 0x7543, 0x4674, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References ------------------------------------------------------------------
		
		auto& pultecFaust = this->getT(0); // project::pultecFaust<NV>
		auto& inv = this->getT(1);         // math::inv<NV>
		auto& gain = this->getT(2);        // core::gain<NV>
		
		// Parameter Connections ------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pultecFaust); // BoostLow -> pultecFaust::BOOSTLow
		
		this->getParameterT(1).connectT(0, pultecFaust); // AttenLow -> pultecFaust::ATTENLow
		
		this->getParameterT(2).connectT(0, pultecFaust); // CPSLow -> pultecFaust::CPSLow
		
		this->getParameterT(3).connectT(0, pultecFaust); // Adjust -> pultecFaust::ADJUST
		
		this->getParameterT(4).connectT(0, pultecFaust); // BoostHi -> pultecFaust::BOOSTHi
		
		this->getParameterT(5).connectT(0, pultecFaust); // AttenHi -> pultecFaust::ATTENHi
		
		this->getParameterT(6).connectT(0, pultecFaust); // CPSHi -> pultecFaust::CPSHi
		
		this->getParameterT(7).connectT(0, pultecFaust); // HiCutF -> pultecFaust::HI_CUTF
		
		// Default Values -------------------------------------------------------------------
		
		; // pultecFaust::BOOSTLow is automated
		; // pultecFaust::ATTENLow is automated
		; // pultecFaust::CPSLow is automated
		; // pultecFaust::ADJUST is automated
		; // pultecFaust::BOOSTHi is automated
		; // pultecFaust::ATTENHi is automated
		; // pultecFaust::CPSHi is automated
		; // pultecFaust::HI_CUTF is automated
		
		inv.setParameterT(0, 0.); // math::inv::Value
		
		gain.setParameterT(0, 0.6); // core::gain::Gain
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1.);
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
// ===================================| Public Definition |===================================

namespace project
{
// polyphonic template declaration

template <int NV>
using pultstereo = wrap::node<pultstereo_impl::instance<NV>>;
}


