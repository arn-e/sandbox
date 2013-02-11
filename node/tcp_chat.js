var net = require('net')
var chatServer = net.createServer(),
    clientList = []

chatServer.on('connection', function(client) {
    client.name = client.remoteAddress + ':' + client.remotePort 
    client.write('Hi!' +  client.name + '!\n');
    clientList.push(client)

    client.on('data', function(data){
        for(var i = 0; i < clientList.length; i += 1) {
          clientList[i].write(data)
        }
    })
})

chatServer.listen(9000)
