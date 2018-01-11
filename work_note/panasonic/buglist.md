# 松下buglist   |
| #        |Priority          |Subject  |
| ------------- |:-------------:| -----:|
| 201550			|	Urgent	  | WAPI-CERT connection failed
| 201549			|	Urgent	  | WAPI-PSK and WAPI-cert cannot connect with DHCP
| 201548			|	Urgent	  | WAPI-PSK cannot connect to internet
| 201547			|	Urgent	  | WAPI reboot issue
| 201546			|	Urgent	  | xhci_hcd "Setup ERROR: setup context command for slot 4"
| 201545			|	Urgent	  | [FZ-B2mk2]Why level of headset jack output drop at around 200Hz?
| 201544			|	Urgent	  | PMIC PROCHOT# Assertion
| 201543			|	Immediate |	[Wi-Fi]Wi-Fi Protected Access II (WPA2) handshake traffic can be manipulated to induce nonce and session key reuse
| 201542			|	Urgent	  | Memory leak issue using MediaCodec
| 201541			|	High	    | [Bluetooth]Fail to forget with BT FW 18.1.1733
| 201538			|	Urgent	  | [Bluetooth]stop receiving BLE data
| 201535			|	Immediate |	Failed resume with powerkey after connected to Wi-Fi AP and paired with BT headset and sleep a night
| 201533			|	Immediate |	[Customer Needs]  Beacon, app says RSSI value is small and waving.
| 201532			|	Immediate |	DRM contents isn't played in mirroring via Miracast if  routed suspend and resume then mirroring again.
| 201510			|	Immediate |	[Wi-Fi] Can not connect to AP during testing using youtube
| 201487			|	Low	      | [HDMI] Show Panasonic logo away from center of the monitor under specific conditions
| 201386			|	High	    | [GTS](3.0_r4)com.google.android.xts.search.GoogleSearchWidgetTest -- testWidgetPresence failed
| 200991			|	Low	      | [CM131mk2] Show "Unable to mount FZ B2D", if DUT turning on with Type-C MTP connection to Linux PC.

----
## 201550
原始耳机输出图形


第一次更改patch
```C
--- AudioConfigurableDomains-src.xml
+++ AudioConfigurableDomains-1st.xml
@@ -625,7 +625,7 @@
           <ParameterBlock Name="equalizer">
             <Component Name="fir">
               <Component Name="switch">
-                <EnumParameter Name="value">on</EnumParameter>
+                <EnumParameter Name="value">off</EnumParameter>
               </Component>
               <Component Name="channel_conf">
                 <EnumParameter Name="value">stereo</EnumParameter>
@@ -1267,7 +1267,7 @@
           <ParameterBlock Name="equalizer">
             <Component Name="fir">
               <Component Name="switch">
-                <EnumParameter Name="value">on</EnumParameter>
+                <EnumParameter Name="value">off</EnumParameter>
               </Component>
               <Component Name="channel_conf">
                 <EnumParameter Name="value">stereo</EnumParameter>

```

第一次更改输出
![test.jpg](https://i.loli.net/2018/01/11/5a56d0563a2b2.jpg)

第二次尝试提高耳机的增益，修改patch如下
```
--- AudioConfigurableDomains-src.xml
+++ AudioConfigurableDomains1226.xml
@@ -410,10 +410,10 @@
       </Configuration>
       <Configuration Name="Default">
         <ConfigurableElement Path="/Audio/REALTEK/SOUND_CARD/OUTPUT/DIGITAL/DAC1/VOLUME/0/LEVEL">
-          <IntegerParameter Name="LEVEL">31</IntegerParameter>
+          <IntegerParameter Name="LEVEL">170</IntegerParameter>
         </ConfigurableElement>
         <ConfigurableElement Path="/Audio/REALTEK/SOUND_CARD/OUTPUT/DIGITAL/DAC1/VOLUME/1/LEVEL">
-          <IntegerParameter Name="LEVEL">31</IntegerParameter>
+          <IntegerParameter Name="LEVEL">170</IntegerParameter>
         </ConfigurableElement>
       </Configuration>
     </Settings>
```
输出图形如下

![test2.jpg](https://i.loli.net/2018/01/11/5a56d16f0690c.jpg)

```
Could you try to mesure the frequency characteristics of headset jack output?

[Notes for this measurement]
1) Settings on FZ-B2D
Settings -> Sound and notification -> Media Volume : 10th steps
Install Audio Test Tone Generator and use sin wave(25Hz-20kHz)

2) Connect stereo mini cable to headpone jack on FZ-B2D and play sin wave of each frequency.

3) Analyze the wav file using PC application (WaveSpectra etc...)

If it is difficult to try it, please ask to Realtek or Intel.
```
