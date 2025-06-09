/* ------------------------------------------------------------
name: "pultecFaust"
Code generated with Faust 2.75.4 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _pultecFaust -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___pultecFaust_H__
#define  ___pultecFaust_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _pultecFaust
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif


struct _pultecFaust final : public ::faust::dsp {
	
	int iRec0[2];
	int iRec1[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fConst2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec2[2];
	int iRec3[2];
	int iRec4[2];
	float fRec5[2];
	int iRec6[2];
	int iRec7[2];
	int iRec8[2];
	float fRec10[2];
	int iRec11[2];
	int iRec12[2];
	float fRec13[2];
	int iRec14[2];
	int iRec15[2];
	int iRec16[2];
	float fRec17[2];
	float fRec18[2];
	int iRec19[2];
	int iRec20[2];
	float fRec21[2];
	int iRec22[2];
	int iRec23[2];
	float fRec24[2];
	int iRec25[2];
	int iRec26[2];
	int iRec27[2];
	float fRec29[2];
	int iRec30[2];
	int iRec31[2];
	float fRec32[2];
	int iRec33[2];
	int iRec34[2];
	int iRec35[2];
	float fRec36[2];
	float fRec37[2];
	
	_pultecFaust() {
	}
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _pultecFaust -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "pultecFaust.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "pultecFaust");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("wdmodels.lib/builddown:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/builddown:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/builddown:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/buildout:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/buildout:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/buildout:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/buildtree:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/buildtree:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/buildtree:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/capacitor:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/capacitor:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/capacitor:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/getres:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/getres:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/getres:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/inductor:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/inductor:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/inductor:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/name", "Faust Wave Digital Model Library");
		m->declare("wdmodels.lib/parallel:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/parallel:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/parallel:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/parres:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/parres:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/parres:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/resVoltage:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/resVoltage:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/resVoltage:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/resistor:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/resistor:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/resistor:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/resistor_Vout:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/resistor_Vout:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/resistor_Vout:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/series:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/series:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/series:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/u_genericNode:author", "Dirk Roosenburg");
		m->declare("wdmodels.lib/u_genericNode:copyright", "Copyright (C) 2020 by Dirk Roosenburg <dirk.roosenburg.30@gmail.com>");
		m->declare("wdmodels.lib/u_genericNode:license", "MIT-style STK-4.3 license");
		m->declare("wdmodels.lib/version", "1.2.1");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 2.0f * fConst0;
		fConst2 = 0.5f / fConst0;
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iRec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec1[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec3[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iRec4[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			iRec6[l6] = 0;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iRec7[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iRec8[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec10[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			iRec11[l10] = 0;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec12[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			iRec14[l13] = 0;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			iRec15[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			iRec16[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec17[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec18[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			iRec19[l18] = 0;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			iRec20[l19] = 0;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec21[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			iRec22[l21] = 0;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			iRec23[l22] = 0;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec24[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			iRec25[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			iRec26[l25] = 0;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			iRec27[l26] = 0;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec29[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			iRec30[l28] = 0;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			iRec31[l29] = 0;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec32[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			iRec33[l31] = 0;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			iRec34[l32] = 0;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			iRec35[l33] = 0;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec36[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec37[l35] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	_pultecFaust* clone() {
		return new _pultecFaust();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("PULTEC PROGRAM EQUALIZER");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("LOW FREQUENCY");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("KNOBS");
		ui_interface->declare(&fHslider6, "0", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("BOOSTLow", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("ATTENLow", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.3e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "style", "menu{'20 Hz':0;'30 Hz':1;'60 Hz':2;'100 Hz':3}");
		ui_interface->addHorizontalSlider("CPSLow", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("BANDWIDTH");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("ADJUST", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.5e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("HIGH FREQUENCY");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("KNOBS");
		ui_interface->declare(&fHslider3, "0", "");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->addHorizontalSlider("BOOSTHi", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(93.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("ATTENHi", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3e+01f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(&fHslider4, "1", "");
		ui_interface->declare(&fHslider4, "style", "menu{'3 kHz':0;'4 kHz':1;'5 kHz':2;'6 kHz':3;'10 kHz':4;'12 kHz':5;'16 kHz':6}");
		ui_interface->addHorizontalSlider("CPSHi", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(6.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openVerticalBox("ATTEN SELECT");
		ui_interface->declare(&fHslider7, "style", "menu{'20':0;'10':1;'5':2}");
		ui_interface->addHorizontalSlider("HI-CUT F", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(3.0f, float(fHslider0)));
		int iSlow1 = fSlow0 >= 2.0f;
		int iSlow2 = fSlow0 >= 1.0f;
		int iSlow3 = fSlow0 >= 3.0f;
		float fSlow4 = ((iSlow1) ? ((iSlow3) ? 1.5e-08f : 2.2e-08f) : ((iSlow2) ? 4.7e-08f : 1e-07f));
		float fSlow5 = 1e+01f * (std::pow(1e+01f, 0.02f * std::max<float>(0.0f, std::min<float>(1.3e+02f, float(fHslider1)))) + -1.0f);
		float fSlow6 = fSlow5 + 1.0f;
		float fSlow7 = 1.0f / fSlow6 + fConst1 * fSlow4;
		float fSlow8 = 1.0f / fSlow7;
		float fSlow9 = 5e+02f * std::log10(std::max<float>(0.0f, std::min<float>(3e+01f, float(fHslider2))) + 1.0f);
		float fSlow10 = fSlow9 + fSlow8 + 1.0f;
		float fSlow11 = fSlow5 + fConst2 / fSlow4 + 1.0f;
		float fSlow12 = fSlow9 + 1.0f;
		float fSlow13 = 1e+03f * (std::pow(1e+01f, 0.02f * std::max<float>(0.0f, std::min<float>(93.0f, float(fHslider3)))) + -1.0f);
		float fSlow14 = std::max<float>(0.0f, std::min<float>(6.0f, float(fHslider4)));
		int iSlow15 = fSlow14 >= 4.0f;
		int iSlow16 = fSlow14 >= 2.0f;
		int iSlow17 = fSlow14 >= 1.0f;
		int iSlow18 = fSlow14 >= 3.0f;
		int iSlow19 = fSlow14 >= 6.0f;
		int iSlow20 = fSlow14 >= 5.0f;
		float fSlow21 = ((iSlow15) ? ((iSlow19) ? 4e-09f : ((iSlow20) ? 5.3e-09f : 6.8e-09f)) : ((iSlow16) ? ((iSlow18) ? 8.3e-09f : 1e-08f) : ((iSlow17) ? 1.25e-08f : 1.5e-08f)));
		float fSlow22 = fConst2 / fSlow21;
		float fSlow23 = ((iSlow15) ? ((iSlow19) ? 0.019f : ((iSlow20) ? 0.023f : 0.035f)) : ((iSlow16) ? ((iSlow18) ? 0.065f : 0.09f) : ((iSlow17) ? 0.1f : 0.175f)));
		float fSlow24 = fConst1 * fSlow23 + fSlow22;
		float fSlow25 = 22.0f * (std::pow(1e+01f, 0.02f * std::max<float>(0.0f, std::min<float>(1.5e+02f, float(fHslider5)))) + -1.0f);
		float fSlow26 = fSlow25 + fSlow24 + 1.0f;
		float fSlow27 = fSlow13 + 1.0f;
		float fSlow28 = 1.0f / fSlow27 + 1.0f / fSlow26;
		float fSlow29 = 1.0f / fSlow28;
		float fSlow30 = ((iSlow1) ? ((iSlow3) ? 3.3e-07f : 4.7e-07f) : ((iSlow2) ? 1e-06f : 2.2e-06f));
		float fSlow31 = 1e+03f * (std::pow(1e+01f, 0.02f * std::max<float>(0.0f, std::min<float>(2e+01f, float(fHslider6)))) + -1.0f);
		float fSlow32 = fSlow31 + 1.0f;
		float fSlow33 = 1.0f / fSlow32 + fConst1 * fSlow30;
		float fSlow34 = 1.0f / fSlow33;
		float fSlow35 = fSlow34 + fSlow29;
		float fSlow36 = fSlow35 + 100010.83f - fSlow13;
		float fSlow37 = 1e+04f * fSlow36;
		float fSlow38 = fSlow29 + 100010.83f - fSlow13;
		float fSlow39 = fSlow38 / fSlow33;
		float fSlow40 = fSlow39 + fSlow37;
		float fSlow41 = 1e+03f * fSlow40;
		float fSlow42 = 1e+03f * fSlow36;
		float fSlow43 = 1e+04f * (fSlow34 + fSlow38);
		float fSlow44 = fSlow34 + 1.1e+04f;
		float fSlow45 = std::max<float>(0.0f, std::min<float>(2.0f, float(fHslider7)));
		float fSlow46 = ((fSlow45 >= 2.0f) ? 1.97e-07f : ((fSlow45 >= 1.0f) ? 9.4e-08f : 4.7e-08f));
		float fSlow47 = fConst2 / fSlow46;
		float fSlow48 = fSlow47 + 75.0f;
		float fSlow49 = 1.0f / fSlow12 + 1.0f / fSlow48;
		float fSlow50 = 1.0f / fSlow49;
		float fSlow51 = fSlow50 + 1001.0f - fSlow9;
		float fSlow52 = fSlow51 * fSlow44;
		float fSlow53 = fSlow10 * (fSlow52 + fSlow43 + fSlow39 + fSlow42);
		float fSlow54 = fSlow29 + 110010.83f - fSlow13;
		float fSlow55 = 1e+03f * fSlow54;
		float fSlow56 = fSlow51 * (fSlow40 + fSlow55);
		float fSlow57 = fSlow56 + fSlow53 + fSlow41;
		float fSlow58 = fSlow52 + 1e+03f / fSlow33;
		float fSlow59 = fSlow13 + fSlow25 + fSlow22 + 2.0f * (fConst0 * fSlow23 + 1.0f);
		float fSlow60 = fSlow31 + fConst2 / fSlow30 + 1.0f;
		float fSlow61 = 1e+04f * fSlow51;
		float fSlow62 = fSlow61 - 1e+03f * fSlow38;
		float fSlow63 = fSlow10 * fSlow62;
		float fSlow64 = fSlow34 + 1e+03f;
		float fSlow65 = fSlow51 * fSlow64;
		float fSlow66 = fSlow42 + fSlow65;
		float fSlow67 = fSlow39 + 1e+04f * (fSlow51 + fSlow36);
		float fSlow68 = fSlow37 + fSlow38 * fSlow64;
		float fSlow69 = fSlow9 + fSlow47 + 76.0f;
		float fSlow70 = fSlow41 + fSlow56 - fSlow53;
		float fSlow71 = fSlow4 * fSlow11;
		float fSlow72 = 1001.0f - fSlow9;
		float fSlow73 = fSlow10 * fSlow44 + 1e+07f;
		float fSlow74 = 1.1e+04f * fSlow10;
		float fSlow75 = fSlow55 + fSlow74;
		float fSlow76 = fSlow10 / fSlow33;
		float fSlow77 = 2e+03f * fSlow38 - 2.0f * fSlow76;
		float fSlow78 = fSlow37 + (fSlow10 + fSlow38) / fSlow33;
		float fSlow79 = fSlow41 + fSlow10 * (fSlow42 + fSlow43 + fSlow39 - fSlow52) - fSlow56;
		float fSlow80 = fSlow65 + (fSlow9 + fSlow8 + 1001.0f) / fSlow33;
		float fSlow81 = fSlow9 + fSlow13;
		float fSlow82 = fSlow50 + fSlow29;
		float fSlow83 = fSlow10 * (fSlow82 + 101011.83f - fSlow81);
		float fSlow84 = fSlow50 + 2001.0f - fSlow9;
		float fSlow85 = fSlow38 * fSlow84 + fSlow83;
		float fSlow86 = fSlow10 * (fSlow29 + fSlow34 + fSlow50 + 101011.83f - fSlow81);
		float fSlow87 = fSlow51 * fSlow38 + fSlow86;
		float fSlow88 = 2e+07f * fSlow38 - 2e+04f * fSlow76;
		float fSlow89 = 1.0f - 2e+04f * ((fSlow42 + fSlow86 + fSlow51 * (fSlow35 + 101010.83f - fSlow13)) / fSlow57);
		float fSlow90 = fSlow33 * fSlow57;
		float fSlow91 = 1.0f - 2.0f * ((fSlow54 * fSlow84 + fSlow10 * (fSlow82 + 112011.83f - fSlow81)) / fSlow90);
		float fSlow92 = fSlow74 + 1e+04f * fSlow84;
		float fSlow93 = fSlow83 + fSlow51 * fSlow54;
		float fSlow94 = fSlow25 + 1.0f;
		float fSlow95 = 1.0f - 2.0f * (fSlow38 * (1e+03f * (fSlow34 + 1e+04f) + fSlow44 * (fSlow10 + fSlow51)) / fSlow57);
		float fSlow96 = fSlow61 - fSlow76;
		float fSlow97 = 100010.83f - fSlow13;
		float fSlow98 = fSlow10 * fSlow58;
		float fSlow99 = fSlow10 * fSlow66;
		float fSlow100 = fSlow10 * fSlow67;
		float fSlow101 = fSlow10 * fSlow68;
		float fSlow102 = fSlow51 * fSlow73;
		float fSlow103 = fSlow51 * fSlow75;
		float fSlow104 = fSlow51 * fSlow77;
		float fSlow105 = fSlow51 * fSlow78;
		float fSlow106 = fSlow51 * fSlow68;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iRec0[0] = 0;
			iRec1[0] = 0;
			float fTemp0 = float(iRec1[1]);
			float fTemp1 = (fConst2 * (fTemp0 / fSlow4) + fSlow6 * fRec2[1]) / fSlow11;
			float fTemp2 = fRec17[1] + fRec18[1];
			float fTemp3 = float(-iRec16[1]) + fTemp2;
			float fTemp4 = float(iRec15[1]);
			float fTemp5 = (fSlow26 * fTemp4 + fSlow27 * fTemp3) / fSlow59;
			float fTemp6 = float(-iRec12[1]) - (0.98275864f * fRec13[1] + 0.0017241379f * float(10 * iRec14[1]));
			float fTemp7 = fTemp6 + fTemp5;
			float fTemp8 = fConst2 * (float(iRec11[1]) / fSlow30);
			float fTemp9 = fSlow32 * fRec10[1] + fTemp8;
			float fTemp10 = float(iRec8[1]);
			float fTemp11 = float(iRec7[1]);
			float fTemp12 = float(iRec6[1]);
			float fTemp13 = fRec5[1] + fTemp12;
			float fTemp14 = float(iRec4[1]);
			float fTemp15 = (fSlow48 * fTemp14 - fSlow12 * fTemp13) / fSlow69;
			float fTemp16 = float(-iRec3[1]) - fTemp15;
			float fTemp17 = float(-iRec0[1]) - fTemp1;
			fRec2[0] = fConst2 * ((fTemp0 - fRec2[1]) / fSlow71) - (((fTemp17 * fSlow70 + 2.0f * fSlow10 * fTemp16 * fSlow68 + 2.0f * fSlow10 * fTemp11 * fSlow67 - 2.0f * fSlow10 * fTemp10 * fSlow66 + 2.0f * (fSlow63 * fTemp9 / fSlow60) + 2.0f * fSlow10 * fTemp7 * fSlow58) / fSlow57 + float(iRec0[1])) / fSlow7 - fSlow12 * fTemp1) / fSlow10;
			iRec3[0] = 0;
			iRec4[0] = 0;
			fRec5[0] = (75.0f * fRec5[1] - fConst2 * ((fSlow48 * (fTemp14 + fTemp13) / fSlow69 - (((fTemp16 * fSlow79 + 2.0f * fTemp17 * fSlow51 * fSlow68 - 2.0f * fSlow51 * fTemp11 * fSlow78 + fSlow51 * fTemp10 * fSlow77 + 2.0f * (fSlow51 * fTemp9 * fSlow75 / fSlow60) + 2.0f * fSlow51 * fTemp7 * fSlow73) / fSlow57 + float(iRec3[1])) / fSlow49 - fSlow72 * fTemp15) / fSlow51) / fSlow46) - fConst2 * (fTemp12 / fSlow46)) / fSlow48;
			iRec6[0] = 0;
			iRec7[0] = 0;
			iRec8[0] = 0;
			float fRec9 = 0.5f * (fTemp10 * fSlow89 + (fTemp16 * fSlow88 - 2e+04f * fTemp17 * fSlow66 - 2e+04f * fTemp11 * fSlow87 - 2e+04f * (fTemp9 * fSlow85 / fSlow60) + 2e+04f * fTemp7 * fSlow80) / fSlow57);
			fRec10[0] = 2.0f * ((fTemp17 * fSlow62 + fTemp16 * fSlow75 - fTemp11 * fSlow93 - fTemp10 * fSlow85 - fTemp7 * fSlow92) / fSlow90) + (fTemp8 + (fTemp9 * fSlow91 - fConst2 * (fRec10[1] / fSlow30))) / fSlow60;
			iRec11[0] = 0;
			iRec12[0] = 0;
			fRec13[0] = float(input0[i0]);
			iRec14[0] = 0;
			iRec15[0] = 0;
			iRec16[0] = 0;
			float fTemp18 = fConst1 * fSlow23 * fRec18[1];
			float fTemp19 = fSlow24 * ((fSlow97 * fTemp5 + (2.0f * (fSlow38 * (fTemp17 * fSlow58 + fTemp16 * fSlow73 - fTemp11 * fSlow96 + fTemp10 * fSlow80 - fTemp9 * fSlow92 / fSlow60) / fSlow57) + fTemp7 * fSlow95 - fTemp6) / fSlow28) / fSlow38 + fSlow26 * (fTemp4 - fTemp3) / fSlow59 + float(iRec16[1])) + fSlow94 * fTemp2;
			fRec17[0] = -((fConst1 * (fSlow23 * fTemp19 / fSlow26) + fConst2 * (fRec17[1] / fSlow21) - fTemp18) / fSlow24);
			fRec18[0] = (fTemp18 - fConst2 * ((fRec17[1] - fTemp19 / fSlow26) / fSlow21)) / fSlow24;
			output0[i0] = FAUSTFLOAT(2e+02f * fRec9);
			iRec19[0] = 0;
			iRec20[0] = 0;
			float fTemp20 = float(iRec20[1]);
			float fTemp21 = (fConst2 * (fTemp20 / fSlow4) + fSlow6 * fRec21[1]) / fSlow11;
			float fTemp22 = fRec36[1] + fRec37[1];
			float fTemp23 = float(-iRec35[1]) + fTemp22;
			float fTemp24 = float(iRec34[1]);
			float fTemp25 = (fSlow26 * fTemp24 + fSlow27 * fTemp23) / fSlow59;
			float fTemp26 = float(-iRec31[1]) - (0.98275864f * fRec32[1] + 0.0017241379f * float(10 * iRec33[1]));
			float fTemp27 = fTemp26 + fTemp25;
			float fTemp28 = fConst2 * (float(iRec30[1]) / fSlow30);
			float fTemp29 = fSlow32 * fRec29[1] + fTemp28;
			float fTemp30 = float(iRec27[1]);
			float fTemp31 = float(iRec26[1]);
			float fTemp32 = float(iRec25[1]);
			float fTemp33 = fRec24[1] + fTemp32;
			float fTemp34 = float(iRec23[1]);
			float fTemp35 = (fSlow48 * fTemp34 - fSlow12 * fTemp33) / fSlow69;
			float fTemp36 = float(-iRec22[1]) - fTemp35;
			float fTemp37 = float(-iRec19[1]) - fTemp21;
			fRec21[0] = fConst2 * ((fTemp20 - fRec21[1]) / fSlow71) - ((float(iRec19[1]) + (fSlow70 * fTemp37 + 2.0f * fSlow101 * fTemp36 + 2.0f * fSlow100 * fTemp31 - 2.0f * fSlow99 * fTemp30 + 2.0f * (fSlow63 * fTemp29 / fSlow60) + 2.0f * fSlow98 * fTemp27) / fSlow57) / fSlow7 - fSlow12 * fTemp21) / fSlow10;
			iRec22[0] = 0;
			iRec23[0] = 0;
			fRec24[0] = (75.0f * fRec24[1] - fConst2 * ((fSlow48 * (fTemp34 + fTemp33) / fSlow69 - (((fSlow79 * fTemp36 + 2.0f * fSlow106 * fTemp37 - 2.0f * fSlow105 * fTemp31 + fSlow104 * fTemp30 + 2.0f * (fSlow103 * fTemp29 / fSlow60) + 2.0f * fSlow102 * fTemp27) / fSlow57 + float(iRec22[1])) / fSlow49 - fSlow72 * fTemp35) / fSlow51) / fSlow46) - fConst2 * (fTemp32 / fSlow46)) / fSlow48;
			iRec25[0] = 0;
			iRec26[0] = 0;
			iRec27[0] = 0;
			float fRec28 = 0.5f * (fSlow89 * fTemp30 + (fSlow88 * fTemp36 - 2e+04f * fSlow66 * fTemp37 - 2e+04f * fSlow87 * fTemp31 - 2e+04f * (fSlow85 * fTemp29 / fSlow60) + 2e+04f * fSlow80 * fTemp27) / fSlow57);
			fRec29[0] = 2.0f * ((fSlow62 * fTemp37 + fSlow75 * fTemp36 - fSlow93 * fTemp31 - fSlow85 * fTemp30 - fSlow92 * fTemp27) / fSlow90) + (fTemp28 + (fSlow91 * fTemp29 - fConst2 * (fRec29[1] / fSlow30))) / fSlow60;
			iRec30[0] = 0;
			iRec31[0] = 0;
			fRec32[0] = float(input1[i0]);
			iRec33[0] = 0;
			iRec34[0] = 0;
			iRec35[0] = 0;
			float fTemp38 = fConst1 * fSlow23 * fRec37[1];
			float fTemp39 = fSlow24 * (fSlow26 * (fTemp24 - fTemp23) / fSlow59 - ((fTemp26 + (2.0f * (fSlow38 * (fSlow96 * fTemp31 - (fSlow58 * fTemp37 + fSlow73 * fTemp36) - fSlow80 * fTemp30 + fSlow92 * fTemp29 / fSlow60) / fSlow57) - fSlow95 * fTemp27)) / fSlow28 - fSlow97 * fTemp25) / fSlow38 + float(iRec35[1])) + fSlow94 * fTemp22;
			fRec36[0] = -((fConst1 * (fSlow23 * fTemp39 / fSlow26) + fConst2 * (fRec36[1] / fSlow21) - fTemp38) / fSlow24);
			fRec37[0] = (fTemp38 - fConst2 * ((fRec36[1] - fTemp39 / fSlow26) / fSlow21)) / fSlow24;
			output1[i0] = FAUSTFLOAT(2e+02f * fRec28);
			iRec0[1] = iRec0[0];
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
			iRec3[1] = iRec3[0];
			iRec4[1] = iRec4[0];
			fRec5[1] = fRec5[0];
			iRec6[1] = iRec6[0];
			iRec7[1] = iRec7[0];
			iRec8[1] = iRec8[0];
			fRec10[1] = fRec10[0];
			iRec11[1] = iRec11[0];
			iRec12[1] = iRec12[0];
			fRec13[1] = fRec13[0];
			iRec14[1] = iRec14[0];
			iRec15[1] = iRec15[0];
			iRec16[1] = iRec16[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
			iRec19[1] = iRec19[0];
			iRec20[1] = iRec20[0];
			fRec21[1] = fRec21[0];
			iRec22[1] = iRec22[0];
			iRec23[1] = iRec23[0];
			fRec24[1] = fRec24[0];
			iRec25[1] = iRec25[0];
			iRec26[1] = iRec26[0];
			iRec27[1] = iRec27[0];
			fRec29[1] = fRec29[0];
			iRec30[1] = iRec30[0];
			iRec31[1] = iRec31[0];
			fRec32[1] = fRec32[0];
			iRec33[1] = iRec33[0];
			iRec34[1] = iRec34[0];
			iRec35[1] = iRec35[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "pultecFaust.dsp"
	#define FAUST_CLASS_NAME "_pultecFaust"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _pultecFaust -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 8
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("PULTEC PROGRAM EQUALIZER/[0]LOW FREQUENCY/[0]KNOBS/BOOSTLow", fHslider6, 0.0f, 0.0f, 2e+01f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("PULTEC PROGRAM EQUALIZER/[0]LOW FREQUENCY/[0]KNOBS/ATTENLow", fHslider1, 0.0f, 0.0f, 1.3e+02f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("PULTEC PROGRAM EQUALIZER/[0]LOW FREQUENCY/CPSLow", fHslider0, 0.0f, 0.0f, 3.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("PULTEC PROGRAM EQUALIZER/[1]BANDWIDTH/ADJUST", fHslider5, 0.0f, 0.0f, 1.5e+02f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("PULTEC PROGRAM EQUALIZER/[2]HIGH FREQUENCY/[0]KNOBS/BOOSTHi", fHslider3, 0.0f, 0.0f, 93.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("PULTEC PROGRAM EQUALIZER/[2]HIGH FREQUENCY/[0]KNOBS/ATTENHi", fHslider2, 0.0f, 0.0f, 3e+01f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("PULTEC PROGRAM EQUALIZER/[2]HIGH FREQUENCY/CPSHi", fHslider4, 0.0f, 0.0f, 6.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("PULTEC PROGRAM EQUALIZER/[3]ATTEN SELECT/HI-CUT F", fHslider7, 0.0f, 0.0f, 2.0f, 1.0f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, BOOSTLow, "PULTEC PROGRAM EQUALIZER/[0]LOW FREQUENCY/[0]KNOBS/BOOSTLow", fHslider6, 0.0f, 0.0f, 2e+01f, 1.0f) \
		p(HORIZONTALSLIDER, ATTENLow, "PULTEC PROGRAM EQUALIZER/[0]LOW FREQUENCY/[0]KNOBS/ATTENLow", fHslider1, 0.0f, 0.0f, 1.3e+02f, 1.0f) \
		p(HORIZONTALSLIDER, CPSLow, "PULTEC PROGRAM EQUALIZER/[0]LOW FREQUENCY/CPSLow", fHslider0, 0.0f, 0.0f, 3.0f, 1.0f) \
		p(HORIZONTALSLIDER, ADJUST, "PULTEC PROGRAM EQUALIZER/[1]BANDWIDTH/ADJUST", fHslider5, 0.0f, 0.0f, 1.5e+02f, 1.0f) \
		p(HORIZONTALSLIDER, BOOSTHi, "PULTEC PROGRAM EQUALIZER/[2]HIGH FREQUENCY/[0]KNOBS/BOOSTHi", fHslider3, 0.0f, 0.0f, 93.0f, 1.0f) \
		p(HORIZONTALSLIDER, ATTENHi, "PULTEC PROGRAM EQUALIZER/[2]HIGH FREQUENCY/[0]KNOBS/ATTENHi", fHslider2, 0.0f, 0.0f, 3e+01f, 1.0f) \
		p(HORIZONTALSLIDER, CPSHi, "PULTEC PROGRAM EQUALIZER/[2]HIGH FREQUENCY/CPSHi", fHslider4, 0.0f, 0.0f, 6.0f, 1.0f) \
		p(HORIZONTALSLIDER, HI-CUT_F, "PULTEC PROGRAM EQUALIZER/[3]ATTEN SELECT/HI-CUT F", fHslider7, 0.0f, 0.0f, 2.0f, 1.0f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
