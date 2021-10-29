require('dotenv').config();

const tmi = require('tmi.js');
const request = require('request'); //npm install request

const client = new tmi.Client({
	options: { debug: true },
	identity: {
		username: process.env.TWITCH_BOT_USERNAME,
		password: process.env.TWITCH_OAUTH_TOKEN
	},
	channels: [ 'codilab' ]
});

client.connect();


client.on('message', (channel, tags, message, self) => {
	// Ignore echoed messages.
	if(self) return;

	if(message.toLowerCase() === '!hello') {
		// "@alca, heya!"
		client.say(channel, `@${tags.username}, heya!`);
	}

	ResultadoPesquisa = message.split(" ",4); //Splice the string to organize the search

    if (ResultadoPesquisa[0] == "!pesquisar")// Function to search any electronic component
    {
        ResultadoPesquisa.splice(0,1); //Removed '!pesquisar'
        ResultadoPesquisa = ResultadoPesquisa.join('%20'); //%20  was used because it'necessary on URL mouser where has blank space.
        link = 'https://br.mouser.com/c/?q='+ResultadoPesquisa; //Link Monted
        MessageToBackChat = "Acesse o link para ver os resultados: " + link + " :) "; //Message to chat message
        client.say(channel, MessageToBackChat);// Return message to chat
    }
    
	if (ResultadoPesquisa[0] == "!liga_amarelo"){
		request("http://192.168.0.108/Y");
		client.say(channel,`Tudo bem @${tags.username}, ligando o LED amarelo!`);
	}
	if (ResultadoPesquisa[0] == "!desliga_amarelo"){
		request("http://192.168.0.108/y");
		client.say(channel,`Tudo bem @${tags.username}, desligando o LED amarelo!`);
	}
	if (ResultadoPesquisa[0] == "!liga_vermelho"){
		request("http://192.168.0.108/R");
		client.say(channel,`Tudo bem @${tags.username}, ligando o LED vermelho!`);
	}
	if (ResultadoPesquisa[0] == "!desliga_vermelho"){
		request("http://192.168.0.108/r");
		client.say(channel,`Tudo bem @${tags.username}, desligando o LED vermelho!`);
	}
	if (ResultadoPesquisa[0] == "!liga_azul"){
		request("http://192.168.0.108/B");
		client.say(channel,`Tudo bem @${tags.username}, ligando o LED Azul!`);
	}
	if (ResultadoPesquisa[0] == "!desliga_azul"){
		request("http://192.168.0.108/b");
		client.say(channel,`Tudo bem @${tags.username}, desligando o LED Azul!`);
	}
});
				
