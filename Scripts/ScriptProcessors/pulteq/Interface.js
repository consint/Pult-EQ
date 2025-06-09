/*
Pult EQ

Creator: Consistent Interruption
License: GPLv3

https://www.consint.net
https://github.com/consint

Created with Hise (https://hise.dev/) 
The Background is based on a SVG background from https://www.svgbackgrounds.com/set/free-svg-backgrounds-and-patterns/
*/

Content.makeFrontInterface(640, 330);

include("icons.js");
include("background.js");

Engine.loadFontAs("{PROJECT_FOLDER}Fonts/Roboto-Medium.ttf", "Roboto-Medium");
Engine.setGlobalFont("Roboto-Medium");

// ##############
// Colours
// ##############
const var textCol = 0xFFBDC6D2;
const var mainCol = 0xFF25445B;
const var blackCol = 0xFF191A1C;
const var blackLighterCol = 0xFF60666C;
const var mainDarkCol = 0xFF1E384B;
const var mainDarkerCol = 0xFF182C3B;
const var mainDarkestCol = 0xFF12212C;
const var mainLightCol = 0xFF2C516C;
const var contrastCol = 0xFFe59dbf;
const var greyLightCol = 0xff9dadbc;

// ##############
// LAF
// ##############
const var laf = Engine.createGlobalScriptLookAndFeel();

// Background
const var pnlBackground = Content.getComponent("pnlBackground");

reg graphicNoise = {
	"alpha": 0.01,
	"monochromatic": 1,
	"scaleFactor": 0.4
};

pnlBackground.setPaintRoutine(function(g)
{
	var a = pnlBackground.getLocalBounds(0);
	var headerHight = 50;
	var masterHight = 60;
	var mainHight = 320 - headerHight;
	
	// Background
	g.setColour(blackCol);
	g.fillRect([0, 0, a[2], a[3]]);
	
	// Overlay
	g.setColour(mainLightCol);
	g.fillRect([0, headerHight+5, a[2], 200]);
	g.fillPath(Background.rectWave, [0, headerHight+180, a[2], 90]);
	
	g.setColour(0xff445677);
	g.fillPath(Background.rectWave, [0, -10, a[2], masterHight+headerHight+18]);
	
	// Main
	g.setColour(Colours.withAlpha(mainLightCol, 0.7));
	g.fillRoundedRectangle([0, headerHight+masterHight+50, a[2], mainHight], 2);
	
	// Waves
	g.setColour(Colours.withAlpha(mainCol, 0.09));
	g.drawPath(Background.wave, [2, 40, a[2]-4, 55], 2);
	g.drawPath(Background.wave, [2, 87, a[2]-4, 55], 2);
	g.drawPath(Background.wave, [2, 134, a[2]-4, 55], 2);
	g.drawPath(Background.wave, [2, 181, a[2]-4, 55], 2);
	g.drawPath(Background.wave, [2, 228, a[2]-4, 55], 2);
	g.drawPath(Background.wave, [2, 275, a[2]-4, 55], 2);
	
	// Header and bottom Background
	g.setColour(blackCol);
	g.fillRect([0, 0, a[2], headerHight]);
	
	// Text Main
	g.setColour(greyLightCol);
	g.fillRoundedRectangle([123, 68, 30, 25], 3); // EQ Background
	g.fillRoundedRectangle([445, 68, 30, 25], 2); // OS Background
	
	g.setColour(mainDarkestCol);
	g.setFont("Roboto-Medium", 13);
	g.drawAlignedText("EQ", [124, 73, 20, 15], "right"); // EQ Text
	g.drawAlignedText("OS", [445, 74, 20, 15], "right"); // OS Text
	
	// Knob Backgrounds
	g.setColour(0xff3c4e6b);
	g.fillEllipse([12, 62, 36, 36]);
	g.fillEllipse([342, 62, 36, 36]);
	g.fillEllipse([547, 62, 36, 36]);
	
	g.setColour(0xff294962);
	g.fillEllipse([35, 132, 60, 60]);
	g.fillEllipse([135, 132, 60, 60]);
	g.fillEllipse([277, 132, 60, 60]);
	g.fillEllipse([387, 132, 60, 60]);
	g.fillEllipse([535, 132, 60, 60]);
	
	g.setColour(blackCol);
	g.drawRoundedRectangle([0, headerHight, a[2], 280], 3, 3);
});

// pnlMain, Mid and Side
const var pnlMain = Content.getComponent("pnlMain");
const var pnlMainMid = Content.getComponent("pnlMainMid");
const var pnlMainSide = Content.getComponent("pnlMainSide");

const var paintGainBack = function(g)
{
	var a = obj.area;
	var alpha = this.get("enabled") == 1 ? 1 : 0.4;
	
	g.setFont("Roboto-Medium", 13);
	g.setColour(Colours.withAlpha(textCol, alpha));
	g.drawAlignedText("Low Frequency", [31, 155, 127, 25], "centred");
	g.drawAlignedText("Hight Frequency", [236, 155, 210, 25], "centred");
	g.drawAlignedText("Atten Frequency", [479, 155, 132, 25], "centred");
};

pnlMain.setPaintRoutine(paintGainBack);
pnlMainMid.setPaintRoutine(paintGainBack);
pnlMainSide.setPaintRoutine(paintGainBack);

// Knobs Gains
laf.registerFunction("drawRotarySlider", function(g, obj)
{
	var a = obj.area;
	var alpha = obj.enabled == 1 ? 1 : 0.4;
	
	// Fill
	var ellipseShift = a[2]*0.1;
	g.setColour(mainDarkestCol);
	g.fillEllipse([ellipseShift, ellipseShift, a[2] - ellipseShift*2, a[2] - ellipseShift*2]);
	
	var startOffset = 2.5;
	var arcThickness = 0.03;
	var arcWidth = 1.0 - 2.0 * arcThickness;
	var endOffset = startOffset * 2.0 * obj.valueNormalized -startOffset;

	g.setColour(Colours.withAlpha(textCol, alpha));
	// Name
	g.setFont("Roboto-Medium", 13);
	g.drawAlignedText(obj.text, [a[0], a[2], a[2], 10], "centred");
	
	// Value
	g.setFont("Roboto-Medium", 12);
	var yShift = 13.5;
	g.drawAlignedText(Engine.doubleToString(obj.value, 2), [a[0], a[2] + yShift, a[2], 10], "centred");
	

	// Arc
	var K = Content.createPath();
	K.addArc([arcThickness * 2, arcThickness * 2, arcWidth - arcThickness * 2, arcWidth - arcThickness * 2], -startOffset, endOffset);
	var pathArea = K.getBounds(a[2]);
	
	var KStyle = {};
	KStyle.EndCapStyle = "rounded";
	KStyle.JointStyle = "curved";
	KStyle.Thickness = a[2] * arcThickness;
	g.drawPath(K, pathArea, KStyle);
	
	// Indicator
	var indiDia = a[2]/10;
	g.rotate(endOffset, [a[2]*0.5, a[2]*0.5]);
	g.fillEllipse([a[2]*0.5 - indiDia*0.5, a[2]/6.25, indiDia, indiDia]);
});

// Knobs General
const var lafDrive = Content.createLocalLookAndFeel();
const var knbDrive = Content.getComponent("knbDrive");
const var knbIn = Content.getComponent("knbIn");
const var knbOut = Content.getComponent("knbOut");
knbDrive.setLocalLookAndFeel(lafDrive);
knbIn.setLocalLookAndFeel(lafDrive);
knbOut.setLocalLookAndFeel(lafDrive);

lafDrive.registerFunction("drawRotarySlider", function(g, obj)
{
	var a = obj.area;
	// Fill
	var ellipseShift = a[3]*0.1;
	g.setColour(mainDarkestCol);
	g.fillEllipse([ellipseShift, ellipseShift, a[3] - ellipseShift*2, a[3] - ellipseShift*2]);
	
	var arcThickness = 0.03;
	var arcWidth = 1.0 - 2.0 * arcThickness;
	
	if (obj.text == "Drive")
	{
		var startOffset = 2.5;
		var endOffset = startOffset * 2.0 * obj.valueNormalized -startOffset;
	}
	else
	{
		var startOffset = 0;
		var endOffset = (2.5 * obj.value) / obj.max;
	}
	
	g.setColour(textCol);
	
	// Name and Value
	if (obj.text == "Drive")
	{
		// Name
		g.setFont("Roboto-Medium", 13);
		g.drawAlignedText(obj.text, [a[3]+2, 8, 32, 10], "centred");
	
		// Value
		g.setFont("Roboto-Medium", 12);
		g.drawAlignedText(obj.value, [a[3]+2, 22.5, 32, 10], "centred");
	}
	else
	{
		// Name
		g.setFont("Roboto-Medium", 13);
		g.drawAlignedText(obj.text, [a[3]+2, 8, 45, 10], "centred");
				
		// value
		g.setFont("Roboto-Medium", 12);
		g.drawAlignedText(Engine.doubleToString(obj.value, 2) + " dB", [a[3]+2, 22.5, 45, 10], "centred");
	}
	
	// Arc
	var K = Content.createPath();
	
	K.addArc([arcThickness * 2, arcThickness * 2, arcWidth - arcThickness * 2, arcWidth - arcThickness * 2], -startOffset, endOffset);
	var pathArea = K.getBounds(a[3]);
	
	var KStyle = {};
	KStyle.EndCapStyle = "rounded";
	KStyle.JointStyle = "curved";
	KStyle.Thickness = a[3] * arcThickness;
	
	g.drawPath(K, pathArea, KStyle);
	
	// Indicator
	var indiDia = a[3]/10;
	g.rotate(endOffset, [a[3]*0.5, a[3]*0.5]);
	g.fillEllipse([a[3]*0.5 - indiDia*0.5, a[3]/6.25, indiDia, indiDia]);
});

// Knobs Radio
const var Y = 7;
const var W = 20;
const var H = 10;

const var knbLowFreq = Content.getComponent("knbLowFreq");
const var knbLowFreqMid = Content.getComponent("knbLowFreqMid");
const var knbLowFreqSide = Content.getComponent("knbLowFreqSide");
const var knbHightFreq = Content.getComponent("knbHightFreq");
const var knbHightFreqMid = Content.getComponent("knbHightFreqMid");
const var knbHightFreqSide = Content.getComponent("knbHightFreqSide");
const var knbAttenFreq = Content.getComponent("knbAttenFreq");
const var knbAttenFreqMid = Content.getComponent("knbAttenFreqMid");
const var knbAttenFreqSide = Content.getComponent("knbAttenFreqSide");
const var knbStereo = Content.getComponent("knbStereo");

const var lafKnobsRadio = Content.createLocalLookAndFeel();

knbLowFreq.setLocalLookAndFeel(lafKnobsRadio);
knbLowFreqMid.setLocalLookAndFeel(lafKnobsRadio);
knbLowFreqSide.setLocalLookAndFeel(lafKnobsRadio);
knbHightFreq.setLocalLookAndFeel(lafKnobsRadio);
knbHightFreqMid.setLocalLookAndFeel(lafKnobsRadio);
knbHightFreqSide.setLocalLookAndFeel(lafKnobsRadio);
knbAttenFreq.setLocalLookAndFeel(lafKnobsRadio);
knbAttenFreqMid.setLocalLookAndFeel(lafKnobsRadio);
knbAttenFreqSide.setLocalLookAndFeel(lafKnobsRadio);
knbStereo.setLocalLookAndFeel(lafKnobsRadio);

const var lowFreqValues = ["20", "30", "60", "100"];
const var lowFreqBounds = [[5, Y, W, H], [35, Y, W, H], [65, Y, W, H], [98, Y, W, H]];
const var hightFreqValues = ["3", "4", "5", "8", "10", "12", "16"];
const var hightFreqBounds = [[5, Y, W, H], [35, Y, W, H], [65, Y, W, H], [95, Y, W, H], [125, Y, W, H], [155, Y, W, H], [185, Y, W, H]];
const var attenFreqValues = ["3", "10", "20"];
const var attenFreqBounds = [[5, Y, W, H], [35, Y, W, H], [65, Y, W, H]];
const var stereoValues = ["Off", "Stereo", "Mid", "Side"];
const var stereoBounds = [[7, Y, 25, H], [43, Y, 35, H], [90, Y, 30, H], [128, Y, 30, H]];

lafKnobsRadio.registerFunction("drawRotarySlider", function(g, obj)
{
	var a = obj.area;
	var alpha = obj.enabled == 1 ? 1 : 0.4;
	var freqValues = [];
	var freqBounds = [];
	var stereoW = 0;
	
	if (obj.text.contains("LowFreq"))
	{
		freqValues = lowFreqValues;
		freqBounds = lowFreqBounds;
	}
	else if (obj.text.contains("HightFreq"))
	{
		freqValues = hightFreqValues;
		freqBounds = hightFreqBounds;
	}
	else if (obj.text.contains("AttenFreq"))
	{
		freqValues = attenFreqValues;
		freqBounds = attenFreqBounds;
	}
	else if (obj.text == "knbStereo")
	{
		freqValues = stereoValues;
		freqBounds = stereoBounds;
		stereoW = 10;
	}
	
	// Background
	g.setColour(mainDarkestCol);
	g.fillRoundedRectangle([0, 0, a[2], a[3]], 3);
	g.fillRect([0, 0, stereoW, a[3]]);
	
	// Values
	g.setFont("Roboto-Medium", 13);
	
	for (i = 0; i < freqValues.length; i++)
	{
		if (i == obj.value)
		{
			g.setColour(Colours.withAlpha(textCol, alpha));
			g.drawAlignedText(freqValues[i], freqBounds[i], "centred");
		}
		else
		{
			g.setColour(Colours.withAlpha(textCol, 0.25));
			g.drawAlignedText(freqValues[i], freqBounds[i], "centred");
		}
	}
});

// Buttons
const var btnLogo = Content.getComponent("btnLogo");
laf.registerFunction("drawToggleButton", function(g, obj)
{
	var a = obj.area;

	obj.value == 1 ? g.setColour(textCol) : g.setColour(blackLighterCol);
	
	if (obj.text.contains("Radio"))
	{
		return;
	}
	else if (obj.text == "BYPASS")
	{
		g.fillPath(bypass, a);
	}
	else if (obj.text == "Settings")
	{
		g.drawPath(settings, a, 1);
	}
	else if (obj.text == "btnLogo")
	{
		g.setColour(textCol);
		g.fillPath(ciLogo, btnLogo.getLocalBounds(0));
	}
	else if (obj.text.contains("consint"))
	{
		g.setFont("Roboto-Medium", 13);
		obj.over == 1 ? g.setColour(0xffffffff) : g.setColour(textCol);
		g.drawAlignedText(obj.text, a, "centred");
	}
});

// Combobox
laf.registerFunction("drawComboBox", function(g, obj)
{
	var a = obj.area;
	
	// Background
    g.setGradientFill([mainDarkerCol, 0, 0, mainDarkestCol, 0, 25]);
    g.fillRoundedRectangle(obj.area, 3);
    if (obj.id == "cmbOS")
    	g.fillRect([0, 0, 10, a[3]]);
	
	// Text
    g.setColour(textCol);
    g.setFont("Roboto-Medium", 13);
    g.drawAlignedText(obj.text, [a[0] + 9, a[1]+1, a[2]-10, a[3]], "left");
    var h = a[3];
    g.fillTriangle([a[0] + a[2] - h/2.75 - 10, a[1] + h/3, h/2.25, h/3.25], Math.PI);
});
laf.registerFunction("drawPopupMenuBackground", function(g, obj)
{
	g.setGradientFill([mainDarkerCol, 0, 0, mainDarkCol, 0, obj.height]);
	g.fillRect([0, 0, obj.width, obj.height]);	
});


// Settings

// pnlSettings
const var pnlSettings = Content.getComponent("pnlSettings");
pnlSettings.setPaintRoutine(function(g)
{
	var a = this.getLocalBounds(0);
	
	g.setColour(mainCol);
	g.setOpacity(0.96);
	g.fillRect(a);
	
	// Settings Border
	g.setColour(textCol);
	g.drawRoundedRectangle([75, 35, a[2]-150, 110], 8, 1);
	
	// Header Settings
	g.setColour(mainCol);
	g.fillRect([109, 34, 72, 2]);
	
	g.setColour(textCol);
	g.setFont("Roboto-Medium", 18);
	g.drawText("Settings", [110, 20, 70, 30]);
	
	g.setColour(blackCol);
	g.drawRoundedRectangle([0, headerHight, a[2], 280], 3, 3);
});

// Panel Labels
const var pnlSettingsOSFilter = Content.getComponent("pnlSettingsOSFilter");
const var pnlSettingsZoom = Content.getComponent("pnlSettingsZoom");

const var paintLabels = function(g)
{
	var a = this.getLocalBounds(0);
	
	g.setFont("Roboto-Medium", 14);
	g.setColour(textCol);
	g.drawAlignedText(this.get("text"), [0, 7, a[2], a[3]*0.5], "right");
};

pnlSettingsOSFilter.setPaintRoutine(paintLabels);
pnlSettingsZoom.setPaintRoutine(paintLabels);

//pnlSettingsAbout
const var pnlSettingsAbout = Content.getComponent("pnlSettingsAbout");
pnlSettingsAbout.setPaintRoutine(function(g)
{
	var a = this.getLocalBounds(0);
	
	g.setColour(textCol);
	g.setFont("Roboto-Medium", 18);
	g.drawAlignedText("Pult EQ", [0, 5, a[2], 20], "centred");
	
	g.setFont("Roboto-Medium", 13);
	g.drawAlignedText("Consistent Interruption", [0, 25, a[2], 20], "centred");
	
	g.setFont("Roboto-Medium", 12);
	g.drawAlignedText("Version 1.0.0", [0, 45, a[2], 20], "centred");
});





























// ##############
// GUI Logic
// ##############

//const var PultEQ = Synth.getEffect("PultEQ");
const var btnBypass = Content.getComponent("btnBypass");
const var hmfxPultStereo = Synth.getEffect("hmfxPultStereo");
const var hmfxPultMidSide = Synth.getEffect("hmfxPultMidSide");
const var hmfxSaturation = Synth.getEffect("hmfxSaturation");
const var GainIn = Synth.getEffect("GainIn");
const var GainOut = Synth.getEffect("GainOut");
const var Sat = Synth.getEffect("hmfxSaturation");
const var cmbOS = Content.getComponent("cmbOS");
const var cmbSettingsFilter = Content.getComponent("cmbSettingsFilter");

inline function setLatency()
{
	local latency = 0;
	
	if (knbStereo.getValue() > 0)
		latency++;
	
	if (knbDrive.getValue() == 0)
	{
		Engine.setLatencySamples(latency);
		return;
	}
	
	if (cmbSettingsFilter.getValue() == 1)
	{
		if (cmbOS.getValue() == 2 )
			latency += 2;
		else if (cmbOS.getValue() == 3)
			latency += 3;
		else if (cmbOS.getValue() > 3)
			latency += 4;
	}
	else
	{
		if (cmbOS.getValue() == 2 )
			latency += 31;
		else if (cmbOS.getValue() == 3)
			latency += 38;
		else if (cmbOS.getValue() == 4)
			latency += 41;
		else if (cmbOS.getValue() == 5)
			latency += 42;
	}
	
	Engine.setLatencySamples(latency);
}

// ##############
// Header
// ##############

// Baypass
inline function onbtnBypassControl(component, value)
{
	if (value)
	{
		GainIn.setBypassed(0);
		GainOut.setBypassed(0);
		knbDrive.changed();
		knbStereo.changed();
	}
	else
	{
		Sat.setBypassed(1);
		hmfxPultStereo.setBypassed(1);
		hmfxPultMidSide.setBypassed(1);
		GainIn.setBypassed(1);
		GainOut.setBypassed(1);
	}
};
Content.getComponent("btnBypass").setControlCallback(onbtnBypassControl);

// Settings
inline function onbtnSettingsControl(component, value)
{
	pnlSettings.set("visible", value);
};
Content.getComponent("btnSettings").setControlCallback(onbtnSettingsControl);

// Logo
const var btnSettings = Content.getComponent("btnSettings");
inline function onbtnLogoControl(component, value)
{
	if (!value)
		return;
	
	if (btnSettings.getValue())
	{
		btnSettings.setValue(0);
		btnSettings.changed();
	}
	else
	{
		btnSettings.setValue(1);
		btnSettings.changed();
	}
};
Content.getComponent("btnLogo").setControlCallback(onbtnLogoControl);

// ##############
// Settings
// ##############

// Zoom factor
const var zoomFactor = [0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0];

inline function oncmbZoomControl(component, value)
{
	Settings.setZoomLevel(zoomFactor[value-1]);
};
Content.getComponent("cmbZoom").setControlCallback(oncmbZoomControl);

// Oversampling Filter
inline function oncmbSettingsFilterControl(component, value)
{
	hmfxSaturation.setAttribute(hmfxSaturation.Filter, value-1);
	setLatency();
};
Content.getComponent("cmbSettingsFilter").setControlCallback(oncmbSettingsFilterControl);

// Link Website
inline function onbtnLinkWebsiteControl(component, value)
{
	if (value)
		Engine.openWebsite("https://www.consint.net");
};
Content.getComponent("btnLinkWebsite").setControlCallback(onbtnLinkWebsiteControl);

// Link GitHub
inline function onbtnLinkGitHubControl(component, value)
{
	if (value)
		Engine.openWebsite("https://github.com/consint");
};
Content.getComponent("btnLinkGitHub").setControlCallback(onbtnLinkGitHubControl);

// Link Ko-fi
inline function onbtnLinkKofiControl(component, value)
{
	if (value)
			Engine.openWebsite("https://ko-fi.com/consint");
};
Content.getComponent("btnLinkKofi").setControlCallback(onbtnLinkKofiControl);



// ##############
// General
// ##############

// Drive
const var comp = [-0.1, -0.1, -0.15, -0.2, -0.3, -0.4, -0.55, -0.85, -1.8, -2.9];

inline function onknbDriveControl(component, value)
{
	if (value == 0)
	{
		Sat.setBypassed(1);
	}
	else
	{		
		if (btnBypass.getValue())
			Sat.setBypassed(0);
		
		local v = (value-1)*0.1;
		
		Sat.setAttribute(Sat.Tube, v);
		Sat.setAttribute(Sat.Gain, comp[value-1]);
	}
	
	setLatency();
};
Content.getComponent("knbDrive").setControlCallback(onknbDriveControl);

// Radio Stereo
const var pnlFreqOverlay = Content.getComponent("pnlFreqOverlay");
const var stereoBtn = [];

inline function onStereoControl(component, value)
{
	if (value)
	{
		knbStereo.setValue(stereoBtn.indexOf(component));
		knbStereo.changed();
	}
}

for (i = 0; i < 4; i++)
{
	stereoBtn.push(Content.getComponent("btnStereo" + i));
	stereoBtn[i].setControlCallback(onStereoControl);
}

inline function onknbStereoControl(component, value)
{
	if (value == 0)
	{
		hmfxPultStereo.setBypassed(1);
		hmfxPultMidSide.setBypassed(1);
		
		pnlMain.set("enabled", 0);
		pnlMainMid.set("enabled", 0);
		pnlMainSide.set("enabled", 0);
		pnlFreqOverlay.set("visible", 1);
		pnlMain.repaint();
		pnlMainMid.repaint();
		pnlMainSide.repaint();
		setLatency();
		return;
	}

	pnlMain.set("enabled", 1);
	pnlMainMid.set("enabled", 1);
	pnlMainSide.set("enabled", 1);
	pnlFreqOverlay.set("visible", 0);
	pnlMain.repaint();
	pnlMainMid.repaint();
	pnlMainSide.repaint();
	
	if (value == 1)
	{
		if (btnBypass.getValue())
			hmfxPultStereo.setBypassed(0);
		
		hmfxPultMidSide.setBypassed(1);
		
		pnlMain.set("visible", 1);
		pnlMainMid.set("visible", 0);
		pnlMainSide.set("visible", 0);
	}
	else if (value == 2)
	{
		if (btnBypass.getValue())
			hmfxPultMidSide.setBypassed(0);
		
		hmfxPultStereo.setBypassed(1);
		
		pnlMain.set("visible", 0);
		pnlMainMid.set("visible", 1);
		pnlMainSide.set("visible", 0);
	}
	else if (value == 3)
	{
		if (btnBypass.getValue())
					hmfxPultMidSide.setBypassed(0);
		
		hmfxPultStereo.setBypassed(1);
		
		pnlMain.set("visible", 0);
		pnlMainMid.set("visible", 0);
		pnlMainSide.set("visible", 1);
	}
	
	setLatency();
};
Content.getComponent("knbStereo").setControlCallback(onknbStereoControl);

// Oversampling
inline function oncmbOSControl(component, value)
{
	Sat.setAttribute(Sat.Oversampling, value-1);
	setLatency();
};
Content.getComponent("cmbOS").setControlCallback(oncmbOSControl);

// ##############
// Main
// ##############

// ##############
// Stereo
// ##############

// Low Frequency
const var lowFreq = [];

inline function onLowFreqControl(component, value)
{
	if (value)
	{
		knbLowFreq.setValue(lowFreq.indexOf(component));
		knbLowFreq.changed();
	}
}

for (i = 0; i < 4; i++)
{
	lowFreq.push(Content.getComponent("btnFreqLow" + i));
	lowFreq[i].setControlCallback(onLowFreqControl);
}

// Hight Frequency
const var hightFreq = [];

inline function onHightFreqControl(component, value)
{
	if (value)
	{
		knbHightFreq.setValue(hightFreq.indexOf(component));
		knbHightFreq.changed();
	}
}

for (i = 0; i < 7; i++)
{
	hightFreq.push(Content.getComponent("btnFreqHight" + i));
	hightFreq[i].setControlCallback(onHightFreqControl);
}

// Hight Atten Frequency
const var hightAttenFreq = [];

inline function onHightAttenFreqControl(component, value)
{
	if (value)
	{
		knbAttenFreq.setValue(hightAttenFreq.indexOf(component));
		knbAttenFreq.changed();
	}
}

for (i = 0; i < 3; i++)
{
	hightAttenFreq.push(Content.getComponent("btnGainHightAtten" + i));
	hightAttenFreq[i].setControlCallback(onHightAttenFreqControl);
}

// Hight Atten
inline function onknbAttenFreqControl(component, value)
{
	hmfxPultStereo.setAttribute(hmfxPultStereo.HiCutF, 2-value);
};
Content.getComponent("knbAttenFreq").setControlCallback(onknbAttenFreqControl);

// Low Boost
inline function onknbBoostLowControl(component, value)
{
	hmfxPultStereo.setAttribute(hmfxPultStereo.BoostLow, value*2);
};
Content.getComponent("knbBoostLow").setControlCallback(onknbBoostLowControl);

// Low Atten
inline function onknbAttenLowControl(component, value)
{
	hmfxPultStereo.setAttribute(hmfxPultStereo.AttenLow, value*13);
};
Content.getComponent("knbAttenLow").setControlCallback(onknbAttenLowControl);

// Hight Boost
inline function onknbBoostHightControl(component, value)
{
	hmfxPultStereo.setAttribute(hmfxPultStereo.BoostHi, value*9.3);
};
Content.getComponent("knbBoostHight").setControlCallback(onknbBoostHightControl);

// Hight Adjust
inline function onknbBandwidthControl(component, value)
{
	hmfxPultStereo.setAttribute(hmfxPultStereo.Adjust, value*15);
};
Content.getComponent("knbBandwidth").setControlCallback(onknbBandwidthControl);

// Hight Atten
inline function onknbAttenHightControl(component, value)
{
	hmfxPultStereo.setAttribute(hmfxPultStereo.AttenHi, value*3);
};
Content.getComponent("knbAttenHight").setControlCallback(onknbAttenHightControl);


// ##############
// Mid
// ##############

// Low Frequency
const var lowFreqMid = [];

inline function onLowFreqMidControl(component, value)
{
	if (value)
	{
		knbLowFreqMid.setValue(lowFreqMid.indexOf(component));
		knbLowFreqMid.changed();
	}
}

for (i = 0; i < 4; i++)
{
	lowFreqMid.push(Content.getComponent("btnFreqLowMid" + i));
	lowFreqMid[i].setControlCallback(onLowFreqMidControl);
}

// Hight Frequency
const var hightFreqMid = [];

inline function onHightFreqMidControl(component, value)
{
	if (value)
	{
		knbHightFreqMid.setValue(hightFreqMid.indexOf(component));
		knbHightFreqMid.changed();
	}
}

for (i = 0; i < 7; i++)
{
	hightFreqMid.push(Content.getComponent("btnFreqHightMid" + i));
	hightFreqMid[i].setControlCallback(onHightFreqMidControl);
}

// Hight Atten Frequency
const var hightAttenFreqMid = [];

inline function onHightAttenFreqMidControl(component, value)
{
	if (value)
	{
		knbAttenFreqMid.setValue(hightAttenFreqMid.indexOf(component));
		knbAttenFreqMid.changed();
	}
}

for (i = 0; i < 3; i++)
{
	hightAttenFreqMid.push(Content.getComponent("btnGainHightAttenMid" + i));
	hightAttenFreqMid[i].setControlCallback(onHightAttenFreqMidControl);
}

// Hight Atten
inline function onknbAttenFreqMidControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.midHiCutF, 2-value);
};
Content.getComponent("knbAttenFreqMid").setControlCallback(onknbAttenFreqMidControl);

// Low Boost
inline function onknbBoostLowMidControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.midBoostLow, value*2);
};
Content.getComponent("knbBoostLowMid").setControlCallback(onknbBoostLowMidControl);

// Low Atten
inline function onknbAttenLowMidControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.midAttenLow, value*13);
};
Content.getComponent("knbAttenLowMid").setControlCallback(onknbAttenLowMidControl);

// Hight Boost
inline function onknbBoostHightMidControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.midBoostHi, value*9.3);
};
Content.getComponent("knbBoostHightMid").setControlCallback(onknbBoostHightMidControl);

// Hight Adjust
inline function onknbBandwidthMidControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.midAdjust, value*15);
};
Content.getComponent("knbBandwidthMid").setControlCallback(onknbBandwidthMidControl);

// Hight Atten
inline function onknbAttenHightMidControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.midAttenHi, value*3);
};
Content.getComponent("knbAttenHightMid").setControlCallback(onknbAttenHightMidControl);


// ##############
// Side
// ##############

// Low Frequency
const var lowFreqSide = [];

inline function onLowFreqSideControl(component, value)
{
	if (value)
	{
		knbLowFreqSide.setValue(lowFreqSide.indexOf(component));
		knbLowFreqSide.changed();
	}
}

for (i = 0; i < 4; i++)
{
	lowFreqSide.push(Content.getComponent("btnFreqLowSide" + i));
	lowFreqSide[i].setControlCallback(onLowFreqSideControl);
}

// Hight Frequency
const var hightFreqSide = [];

inline function onHightFreqSideControl(component, value)
{
	if (value)
	{
		knbHightFreqSide.setValue(hightFreqSide.indexOf(component));
		knbHightFreqSide.changed();
	}
}

for (i = 0; i < 7; i++)
{
	hightFreqSide.push(Content.getComponent("btnFreqHightSide" + i));
	hightFreqSide[i].setControlCallback(onHightFreqSideControl);
}

// Hight Atten Frequency
const var hightAttenFreqSide = [];

inline function onHightAttenFreqSideControl(component, value)
{
	if (value)
	{
		knbAttenFreqSide.setValue(hightAttenFreqSide.indexOf(component));
		knbAttenFreqSide.changed();
	}
}

for (i = 0; i < 3; i++)
{
	hightAttenFreqSide.push(Content.getComponent("btnGainHightAttenSide" + i));
	hightAttenFreqSide[i].setControlCallback(onHightAttenFreqSideControl);
}

// Hight Atten
inline function onknbAttenFreqSideControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.sideHiCutF, 2-value);
};
Content.getComponent("knbAttenFreqSide").setControlCallback(onknbAttenFreqSideControl);

// Low Boost
inline function onknbBoostLowSideControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.sideBoostLow, value*2);
};
Content.getComponent("knbBoostLowSide").setControlCallback(onknbBoostLowSideControl);

// Low Atten
inline function onknbAttenLowSideControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.sideAttenLow, value*13);
};
Content.getComponent("knbAttenLowSide").setControlCallback(onknbAttenLowSideControl);

// Hight Boost
inline function onknbBoostHightSideControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.sideBoostHi, value*9.3);
};
Content.getComponent("knbBoostHightSide").setControlCallback(onknbBoostHightSideControl);

// Hight Adjust
inline function onknbBandwidthSideControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.sideAdjust, value*15);
};
Content.getComponent("knbBandwidthSide").setControlCallback(onknbBandwidthSideControl);

// Hight Atten
inline function onknbAttenHightSideControl(component, value)
{
	hmfxPultMidSide.setAttribute(hmfxPultMidSide.sideAttenHi, value*3);
};
Content.getComponent("knbAttenHightSide").setControlCallback(onknbAttenHightSideControl);
function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 