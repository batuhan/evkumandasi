var SerialPort = require('serialport').SerialPort, 
fs = require('fs'),
express = require('express'),
http = require('http'),
path = require('path'),
app = express(),
port = '/dev/ttyAMC0',
relays = {
  first: {
    state: false,
    to_open: 'w',
    to_close: 'q'
  },
  second: {
    state: false,
    to_open: 'r',
    to_close: 'e'
  },
  third: {
    state: false,
    to_open: 'y',
    to_close: 't'
  },
};

function get_relay_state(relay){
  return eval('relays.' + relay + '.state');
}
function set_relay_state(relay, state){
  return eval('relays.' + relay + '.state = ' + state + ';');
}
function get_relay_to_open(relay){
  return eval('relays.' + relay + '.to_open');
}
function get_relay_to_close(relay){
  return eval('relays.' + relay + '.to_close');
}

app.use(express.bodyParser());
app.use(express.static(path.join(__dirname, 'public')));

console.log("Başlatılıyor...");

var serialPort = new SerialPort("/dev/tty.usbmodem1411", {
  baudrate: 9600
}); 

app.get('/', function(req, res) {
  return res.sendfile('index.html');
});

app.get('/relays', function(req, res){
  if(get_relay_state(req.query.relay) == true){
    console.log('kapanıyor.')
    serialPort.write(get_relay_to_close(req.query.relay));
    set_relay_state(req.query.relay, false);
    console.log(relays);
  }else{
    console.log('açılıyor.')
    serialPort.write(get_relay_to_open(req.query.relay));
    set_relay_state(req.query.relay, true);
    console.log(relays);
  }
  res.header("Access-Control-Allow-Origin", "*");
  res.end('');
});

fs.stat(port, function(err, stats) {
  if (err != null) {
    console.log("cihaz bağlı değil sanırsam: " + port);
    process.exit();
  }
  app.listen(3000);
  console.log('Başlatıldı!');
});
