#pragma once

#include "pultec_mono.h"
#include "pultec_mono.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace pultmidside_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using mid_chain_t = container::chain<parameter::empty, 
                                     wrap::fix<1, project::pultec_mono<NV>>>;

template <int NV> using side_chain_t = mid_chain_t<NV>;

template <int NV>
using ms_splitter_t = container::multi<parameter::empty, 
                                       wrap::fix<1, mid_chain_t<NV>>, 
                                       wrap::fix<1, side_chain_t<NV>>>;

template <int NV>
using mid_side1_t = container::chain<parameter::empty, 
                                     wrap::fix<2, routing::ms_decode>, 
                                     ms_splitter_t<NV>, 
                                     routing::ms_encode>;

namespace pultmidside_t_parameters
{
// Parameter list for pultmidside_impl::pultmidside_t ----------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(midBoostLow_InputRange, 
                             0., 
                             20., 
                             1.);
DECLARE_PARAMETER_RANGE_SKEW(midBoostLow_0Range, 
                             0., 
                             20., 
                             0.8);

template <int NV>
using midBoostLow_0 = parameter::from0To1<project::pultec_mono<NV>, 
                                          0, 
                                          midBoostLow_0Range>;

template <int NV>
using midBoostLow = parameter::chain<midBoostLow_InputRange, midBoostLow_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(midAttenLow_InputRange, 
                             0., 
                             130., 
                             1.);
DECLARE_PARAMETER_RANGE_SKEW(midAttenLow_0Range, 
                             0., 
                             130., 
                             3.5);

template <int NV>
using midAttenLow_0 = parameter::from0To1<project::pultec_mono<NV>, 
                                          1, 
                                          midAttenLow_0Range>;

template <int NV>
using midAttenLow = parameter::chain<midAttenLow_InputRange, midAttenLow_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(midAdjust_InputRange, 
                             0., 
                             150., 
                             1.);
DECLARE_PARAMETER_RANGE_SKEW(midAdjust_0Range, 
                             0., 
                             150., 
                             4.);

template <int NV>
using midAdjust_0 = parameter::from0To1<project::pultec_mono<NV>, 
                                        3, 
                                        midAdjust_0Range>;

template <int NV>
using midAdjust = parameter::chain<midAdjust_InputRange, midAdjust_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(midBoostHi_InputRange, 
                             0., 
                             93., 
                             1.);
DECLARE_PARAMETER_RANGE_SKEW(midBoostHi_0Range, 
                             0., 
                             93., 
                             5.);

template <int NV>
using midBoostHi_0 = parameter::from0To1<project::pultec_mono<NV>, 
                                         4, 
                                         midBoostHi_0Range>;

template <int NV>
using midBoostHi = parameter::chain<midBoostHi_InputRange, midBoostHi_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(sideBoostLow_InputRange, 
                             0., 
                             20., 
                             1.);
template <int NV> using sideBoostLow_0 = midBoostLow_0<NV>;

template <int NV>
using sideBoostLow = parameter::chain<sideBoostLow_InputRange, 
                                      sideBoostLow_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(sideAttenLow_InputRange, 
                             0., 
                             130., 
                             1.);
template <int NV> using sideAttenLow_0 = midAttenLow_0<NV>;

template <int NV>
using sideAttenLow = parameter::chain<sideAttenLow_InputRange, 
                                      sideAttenLow_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(sideAdjust_InputRange, 
                             0., 
                             150., 
                             1.);
template <int NV> using sideAdjust_0 = midAdjust_0<NV>;

template <int NV>
using sideAdjust = parameter::chain<sideAdjust_InputRange, sideAdjust_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(sideBoostHi_InputRange, 
                             0., 
                             93., 
                             1.);
template <int NV> using sideBoostHi_0 = midBoostHi_0<NV>;

template <int NV>
using sideBoostHi = parameter::chain<sideBoostHi_InputRange, sideBoostHi_0<NV>>;

template <int NV>
using midCPSLow = parameter::plain<project::pultec_mono<NV>, 
                                   2>;
template <int NV>
using midAttenHi = parameter::plain<project::pultec_mono<NV>, 
                                    5>;
template <int NV>
using midCPSHi = parameter::plain<project::pultec_mono<NV>, 
                                  6>;
template <int NV>
using midHiCutF = parameter::plain<project::pultec_mono<NV>, 
                                   7>;
template <int NV> using sideCPSLow = midCPSLow<NV>;
template <int NV> using sideAttenHi = midAttenHi<NV>;
template <int NV> using sideCPSHi = midCPSHi<NV>;
template <int NV> using sideHiCutF = midHiCutF<NV>;
template <int NV>
using pultmidside_t_plist = parameter::list<midBoostLow<NV>, 
                                            midAttenLow<NV>, 
                                            midCPSLow<NV>, 
                                            midAdjust<NV>, 
                                            midBoostHi<NV>, 
                                            midAttenHi<NV>, 
                                            midCPSHi<NV>, 
                                            midHiCutF<NV>, 
                                            sideBoostLow<NV>, 
                                            sideAttenLow<NV>, 
                                            sideCPSLow<NV>, 
                                            sideAdjust<NV>, 
                                            sideBoostHi<NV>, 
                                            sideAttenHi<NV>, 
                                            sideCPSHi<NV>, 
                                            sideHiCutF<NV>>;
}

template <int NV>
using pultmidside_t_ = container::chain<pultmidside_t_parameters::pultmidside_t_plist<NV>, 
                                        wrap::fix<2, mid_side1_t<NV>>, 
                                        math::inv<NV>, 
                                        core::gain<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public pultmidside_impl::pultmidside_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(pultmidside);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(290)
		{
			0x005B, 0x0000, 0x6D00, 0x6469, 0x6F42, 0x736F, 0x4C74, 0x776F, 
            0x0000, 0x0000, 0x0000, 0xA000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0001, 0x0000, 0x696D, 0x4164, 0x7474, 
            0x6E65, 0x6F4C, 0x0077, 0x0000, 0x0000, 0x0000, 0x4302, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 0x0000, 0x6D00, 
            0x6469, 0x5043, 0x4C53, 0x776F, 0x0000, 0x0000, 0x0000, 0x4000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0003, 
            0x0000, 0x696D, 0x4164, 0x6A64, 0x7375, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x4316, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x045B, 0x0000, 0x6D00, 0x6469, 0x6F42, 0x736F, 0x4874, 0x0069, 
            0x0000, 0x0000, 0x0000, 0x42BA, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x055B, 0x0000, 0x6D00, 0x6469, 0x7441, 0x6574, 
            0x486E, 0x0069, 0x0000, 0x0000, 0x0000, 0x41F0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x065B, 0x0000, 0x6D00, 0x6469, 
            0x5043, 0x4853, 0x0069, 0x0000, 0x0000, 0x0000, 0x40C0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x075B, 0x0000, 0x6D00, 
            0x6469, 0x6948, 0x7543, 0x4674, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0008, 
            0x0000, 0x6973, 0x6564, 0x6F42, 0x736F, 0x4C74, 0x776F, 0x0000, 
            0x0000, 0x0000, 0xA000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0009, 0x0000, 0x6973, 0x6564, 0x7441, 0x6574, 
            0x4C6E, 0x776F, 0x0000, 0x0000, 0x0000, 0x0200, 0x0043, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000A, 0x0000, 0x6973, 
            0x6564, 0x5043, 0x4C53, 0x776F, 0x0000, 0x0000, 0x0000, 0x4000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000B, 
            0x0000, 0x6973, 0x6564, 0x6441, 0x756A, 0x7473, 0x0000, 0x0000, 
            0x0000, 0x1600, 0x0043, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x000C, 0x0000, 0x6973, 0x6564, 0x6F42, 0x736F, 0x4874, 
            0x0069, 0x0000, 0x0000, 0x0000, 0x42BA, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0D5B, 0x0000, 0x7300, 0x6469, 0x4165, 
            0x7474, 0x6E65, 0x6948, 0x0000, 0x0000, 0x0000, 0xF000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000E, 0x0000, 
            0x6973, 0x6564, 0x5043, 0x4853, 0x0069, 0x0000, 0x0000, 0x0000, 
            0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0F5B, 
            0x0000, 0x7300, 0x6469, 0x4865, 0x4369, 0x7475, 0x0046, 0x0000, 
            0x0000, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& mid_side1 = this->getT(0);                            // pultmidside_impl::mid_side1_t<NV>
		auto& decoder = this->getT(0).getT(0);                      // routing::ms_decode
		auto& ms_splitter = this->getT(0).getT(1);                  // pultmidside_impl::ms_splitter_t<NV>
		auto& mid_chain = this->getT(0).getT(1).getT(0);            // pultmidside_impl::mid_chain_t<NV>
		auto& pultec_mono = this->getT(0).getT(1).getT(0).getT(0);  // project::pultec_mono<NV>
		auto& side_chain = this->getT(0).getT(1).getT(1);           // pultmidside_impl::side_chain_t<NV>
		auto& pultec_mono1 = this->getT(0).getT(1).getT(1).getT(0); // project::pultec_mono<NV>
		auto& encoder = this->getT(0).getT(2);                      // routing::ms_encode
		auto& inv = this->getT(1);                                  // math::inv<NV>
		auto& gain = this->getT(2);                                 // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pultec_mono); // midBoostLow -> pultec_mono::BOOSTLow
		
		this->getParameterT(1).connectT(0, pultec_mono); // midAttenLow -> pultec_mono::ATTENLow
		
		this->getParameterT(2).connectT(0, pultec_mono); // midCPSLow -> pultec_mono::CPSLow
		
		this->getParameterT(3).connectT(0, pultec_mono); // midAdjust -> pultec_mono::ADJUST
		
		this->getParameterT(4).connectT(0, pultec_mono); // midBoostHi -> pultec_mono::BOOSTHi
		
		this->getParameterT(5).connectT(0, pultec_mono); // midAttenHi -> pultec_mono::ATTENHi
		
		this->getParameterT(6).connectT(0, pultec_mono); // midCPSHi -> pultec_mono::CPSHi
		
		this->getParameterT(7).connectT(0, pultec_mono); // midHiCutF -> pultec_mono::HI_CUTF
		
		this->getParameterT(8).connectT(0, pultec_mono1); // sideBoostLow -> pultec_mono1::BOOSTLow
		
		this->getParameterT(9).connectT(0, pultec_mono1); // sideAttenLow -> pultec_mono1::ATTENLow
		
		this->getParameterT(10).connectT(0, pultec_mono1); // sideCPSLow -> pultec_mono1::CPSLow
		
		this->getParameterT(11).connectT(0, pultec_mono1); // sideAdjust -> pultec_mono1::ADJUST
		
		this->getParameterT(12).connectT(0, pultec_mono1); // sideBoostHi -> pultec_mono1::BOOSTHi
		
		this->getParameterT(13).connectT(0, pultec_mono1); // sideAttenHi -> pultec_mono1::ATTENHi
		
		this->getParameterT(14).connectT(0, pultec_mono1); // sideCPSHi -> pultec_mono1::CPSHi
		
		this->getParameterT(15).connectT(0, pultec_mono1); // sideHiCutF -> pultec_mono1::HI_CUTF
		
		// Default Values --------------------------------------------------------------------------
		
		; // pultec_mono::BOOSTLow is automated
		; // pultec_mono::ATTENLow is automated
		; // pultec_mono::CPSLow is automated
		; // pultec_mono::ADJUST is automated
		; // pultec_mono::BOOSTHi is automated
		; // pultec_mono::ATTENHi is automated
		; // pultec_mono::CPSHi is automated
		; // pultec_mono::HI_CUTF is automated
		
		; // pultec_mono1::BOOSTLow is automated
		; // pultec_mono1::ATTENLow is automated
		; // pultec_mono1::CPSLow is automated
		; // pultec_mono1::ADJUST is automated
		; // pultec_mono1::BOOSTHi is automated
		; // pultec_mono1::ATTENHi is automated
		; // pultec_mono1::CPSHi is automated
		; // pultec_mono1::HI_CUTF is automated
		
		inv.setParameterT(0, 0.); // math::inv::Value
		
		gain.setParameterT(0, 0.6); // core::gain::Gain
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 1.);
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
using pultmidside = wrap::node<pultmidside_impl::instance<NV>>;
}


