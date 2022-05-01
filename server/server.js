const exp = require('express');
const { json } = require('express/lib/response');

const app = exp();

// app.listen('3300',console.log('http://localhost:3300'));
app.use(exp.urlencoded({extended:true}))
app.use(exp.json())
app.set('view engine','ejs')

var net = require('net');
var count = 0;

// var server = net.createServer(function(socket) {
const server = new net.Server();

// socket.pipe(socket);  
// hangs after 41020 writes
server.listen(3300,function(){
    console.log('server listen');
})
server.on('connection', function(socket) {

    console.log('connection') ;
    socket.write('chavy'); 


    socket.on('data', function(chunk) {
        console.log(chunk+"chavy!!!!!!!");
    });

    socket.on('end', function() {
        console.info('Socket end');
    });

    socket.on('error', function(err) {
        console.error('Socket error: ' + err);
    });

    socket.on('close', function(err) {
        console.error('close: ');
    });

});