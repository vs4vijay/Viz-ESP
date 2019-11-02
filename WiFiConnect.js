var ssid = '0xSpaceTime';
var password = '';

var wifi = require('Wifi');

wifi.connect(ssid, { password: password }, function() {
    console.log('Connected to Wifi.  IP address is:', wifi.getIP().ip);
    wifi.save(); // Next reboot will auto-connect
});