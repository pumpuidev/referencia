//querySelectors by details
var input = document.querySelector('.input_text');
var main = document.querySelector('#name');
var temp = document.querySelector('.temp');
var button= document.querySelector('.submit');

//city filter
button.addEventListener('click', function(name){
fetch('https://api.openweathermap.org/data/2.5/weather?q='+input.value+'&appid=4e79125c06f3e5e33258f5749d22989f') //fetch datas from api
.then(response => response.json()) //convert data to json
.then(data => {
  var tempValue = data['main']['temp']; //temperature from api
  var nameValue = data['name'];			//city name from api
  main.innerHTML = nameValue;			//city name to html
  temp.innerHTML = Math.round(parseFloat(tempValue)-273.15) + '&deg;C'; //city temperature to html
  input.value ="";						//assign variable
})
.catch(err => alert("Database does not include this city!")); //fetch rejects errors
})

//london with comments
function position( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID+ '&appid=4e79125c06f3e5e33258f5749d22989f') //fetch datas
	.then(function(resp) { return resp.json() }) //convert data to json
	.then(function(data) {
		param(data);							//call param function
	})
}
function param( d ) {							//declare param function
  var celcius = Math.round(parseFloat(d.main.temp)-273.15);		//covert temperature to cel
	var fahrenheit = Math.round(((parseFloat(d.main.temp)-273.15)*1.8)+32);		//covert temperature to fahr
	document.getElementById('temp').innerHTML = celcius + '&deg;C';				//temp to html
	document.getElementById('location').innerHTML = d.name;						//city to html
}
//new york
function positionNY( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramNY(data);
	})
}
function paramNY( dNY ) {
  var celciusNY = Math.round(parseFloat(dNY.main.temp)-273.15);
	var fahrenheitNY = Math.round(((parseFloat(dNY.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempNY').innerHTML = celciusNY + '&deg;C';
	document.getElementById('locationNY').innerHTML = dNY.name;
}
//beijing
function positionBeijing( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramBeijing(data);
	})
}
function paramBeijing( dBeijing ) {
  var celciusBeijing = Math.round(parseFloat(dBeijing.main.temp)-273.15);
	var fahrenheitBeijing = Math.round(((parseFloat(dBeijing.main.temp)-273.15)*1.8)+32);
  
	document.getElementById('tempBeijing').innerHTML = celciusBeijing + '&deg;C';
	document.getElementById('locationBeijing').innerHTML = dBeijing.name;
}
//los angeles
function positionLA2( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramLA2(data);
	})
}
function paramLA2( dLA2 ) {
  var celciusLA2 = Math.round(parseFloat(dLA2.main.temp)-273.15);
	var fahrenheitLA2 = Math.round(((parseFloat(dLA2.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempLA2').innerHTML = celciusLA2 + '&deg;C';
	document.getElementById('locationLA2').innerHTML = dLA2.name;
}
//budapest
function positionBUDA( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramBUDA(data);
	})
}
function paramBUDA( dBUDA ) {
  var celciusBUDA = Math.round(parseFloat(dBUDA.main.temp)-273.15);
	var fahrenheitBUDA = Math.round(((parseFloat(dBUDA.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempBUDA').innerHTML = celciusBUDA + '&deg;C';
	document.getElementById('locationBUDA').innerHTML = dBUDA.name;
}
//vienna
function positionVienna( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramVienna(data);
	})
}
function paramVienna( dVienna ) {
  var celciusVienna = Math.round(parseFloat(dVienna.main.temp)-273.15);
	var fahrenheitVienna = Math.round(((parseFloat(dVienna.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempVienna').innerHTML = celciusVienna + '&deg;C';
	document.getElementById('locationVienna').innerHTML = dVienna.name;
}
//Prague
function positionPrague( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramPrague(data);
	})
}
function paramPrague( dPrague ) {
  var celciusPrague = Math.round(parseFloat(dPrague.main.temp)-273.15);
	var fahrenheitPrague = Math.round(((parseFloat(dPrague.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempPrague').innerHTML = celciusPrague + '&deg;C';
	document.getElementById('locationPrague').innerHTML = dPrague.name;
}
//berlin
function positionBerlin( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramBerlin(data);
	})
}
function paramBerlin( dBerlin ) {
  var celciusBerlin = Math.round(parseFloat(dBerlin.main.temp)-273.15);
	var fahrenheitBerlin = Math.round(((parseFloat(dBerlin.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempBerlin').innerHTML = celciusBerlin + '&deg;C';
	document.getElementById('locationBerlin').innerHTML = dBerlin.name;
}
//paris
function positionParis( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramParis(data);
	})
}
function paramParis( dParis ) {
  var celciusParis = Math.round(parseFloat(dParis.main.temp)-273.15);
	var fahrenheitParis = Math.round(((parseFloat(dParis.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempParis').innerHTML = celciusParis + '&deg;C';
	document.getElementById('locationParis').innerHTML = dParis.name;
}
//Madrid
function positionMadrid( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramMadrid(data);
	})
}
function paramMadrid( dMadrid ) {
  var celciusMadrid = Math.round(parseFloat(dMadrid.main.temp)-273.15);
	var fahrenheitMadrid = Math.round(((parseFloat(dMadrid.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempMadrid').innerHTML = celciusMadrid + '&deg;C';
	document.getElementById('locationMadrid').innerHTML = dMadrid.name;
}
//barcelona
function positionBarcelona( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramBarcelona(data);
	})
}
function paramBarcelona( dBarcelona ) {
  var celciusBarcelona = Math.round(parseFloat(dBarcelona.main.temp)-273.15);
	var fahrenheitBarcelona = Math.round(((parseFloat(dBarcelona.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempBarcelona').innerHTML = celciusBarcelona + '&deg;C';
	document.getElementById('locationBarcelona').innerHTML = dBarcelona.name;
}
//lisboa
function positionLisbon( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramLisbon(data);
	})
}
function paramLisbon( dLisbon ) {
  var celciusLisbon = Math.round(parseFloat(dLisbon.main.temp)-273.15);
	var fahrenheitLisbon = Math.round(((parseFloat(dLisbon.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempLisbon').innerHTML = celciusLisbon + '&deg;C';
	document.getElementById('locationLisbon').innerHTML = dLisbon.name;
}
//Moscow
function positionMoscow( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramMoscow(data);
	})
}
function paramMoscow( dMoscow ) {
  var celciusMoscow = Math.round(parseFloat(dMoscow.main.temp)-273.15);
	var fahrenheitMoscow = Math.round(((parseFloat(dMoscow.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempMoscow').innerHTML = celciusMoscow + '&deg;C';
	document.getElementById('locationMoscow').innerHTML = dMoscow.name;
}
//Istanbul
function positionIstanbul( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramIstanbul(data);
	})
}
function paramIstanbul( dIstanbul ) {
  var celciusIstanbul = Math.round(parseFloat(dIstanbul.main.temp)-273.15);
	var fahrenheitIstanbul = Math.round(((parseFloat(dIstanbul.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempIstanbul').innerHTML = celciusIstanbul + '&deg;C';
	document.getElementById('locationIstanbul').innerHTML = dIstanbul.name;
}
//cairo
function positionlCairol( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramlCairol(data);
	})
}
function paramlCairol( dlCairol ) {
  var celciuslCairol = Math.round(parseFloat(dlCairol.main.temp)-273.15);
	var fahrenheitlCairol = Math.round(((parseFloat(dlCairol.main.temp)-273.15)*1.8)+32);
	document.getElementById('templCairol').innerHTML = celciuslCairol + '&deg;C';
	document.getElementById('locationlCairol').innerHTML = dlCairol.name;
}
//dubai
function positionDubai( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramDubai(data);
	})
}
function paramDubai( dDubai ) {
  var celciusDubai = Math.round(parseFloat(dDubai.main.temp)-273.15);
	var fahrenheitDubai = Math.round(((parseFloat(dDubai.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempDubai').innerHTML = celciusDubai + '&deg;C';
	document.getElementById('locationDubai').innerHTML = dDubai.name;
}
//tehran
function positionTehran( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramTehran(data);
	})
}
function paramTehran( dTehran ) {
  var celciusTehran = Math.round(parseFloat(dTehran.main.temp)-273.15);
	var fahrenheitTehran = Math.round(((parseFloat(dTehran.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempTehran').innerHTML = celciusTehran + '&deg;C';
	document.getElementById('locationTehran').innerHTML = dTehran.name;
}
//Jerusalem
function positionJerusalem( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramJerusalem(data);
	})
}
function paramJerusalem( dJerusalem ) {
  var celciusJerusalem = Math.round(parseFloat(dJerusalem.main.temp)-273.15);
	var fahrenheitJerusalem = Math.round(((parseFloat(dJerusalem.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempJerusalem').innerHTML = celciusJerusalem + '&deg;C';
	document.getElementById('locationJerusalem').innerHTML = dJerusalem.name;
}
//Delhi
function positionDelhi( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramDelhi(data);
	})
}
function paramDelhi( dDelhi ) {
  var celciusDelhi = Math.round(parseFloat(dDelhi.main.temp)-273.15);
	var fahrenheitDelhi = Math.round(((parseFloat(dDelhi.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempDelhi').innerHTML = celciusDelhi + '&deg;C';
	document.getElementById('locationDelhi').innerHTML = dDelhi.name;
}
//Bangkok
function positionBangkok( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramBangkok(data);
	})
}
function paramBangkok( dBangkok ) {
  var celciusBangkok = Math.round(parseFloat(dBangkok.main.temp)-273.15);
	var fahrenheitBangkok = Math.round(((parseFloat(dBangkok.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempBangkok').innerHTML = celciusBangkok + '&deg;C';
	document.getElementById('locationBangkok').innerHTML = dBangkok.name;
}
//Shanghai
function positionShanghai( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramShanghai(data);
	})
}
function paramShanghai( dShanghai ) {
  var celciusShanghai = Math.round(parseFloat(dShanghai.main.temp)-273.15);
	var fahrenheitShanghai = Math.round(((parseFloat(dShanghai.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempShanghai').innerHTML = celciusShanghai + '&deg;C';
	document.getElementById('locationShanghai').innerHTML = dShanghai.name;
}
//Tokyo
function positionTokyo( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramTokyo(data);
	})
}
function paramTokyo( dTokyo ) {
  var celciusTokyo = Math.round(parseFloat(dTokyo.main.temp)-273.15);
	var fahrenheitTokyo = Math.round(((parseFloat(dTokyo.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempTokyo').innerHTML = celciusTokyo + '&deg;C';
	document.getElementById('locationTokyo').innerHTML = dTokyo.name;
}
//sydney
function positionSydney( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramSydney(data);
	})
}
function paramSydney( dSydney ) {
  var celciusSydney = Math.round(parseFloat(dSydney.main.temp)-273.15);
	var fahrenheitSydney = Math.round(((parseFloat(dSydney.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempSydney').innerHTML = celciusSydney + '&deg;C';
	document.getElementById('locationSydney').innerHTML = dSydney.name;
}
//CapeTown
function positionCapeTown( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramCapeTown(data);
	})
}
function paramCapeTown( dCapeTown ) {
  var celciusCapeTown = Math.round(parseFloat(dCapeTown.main.temp)-273.15);
	var fahrenheitCapeTown = Math.round(((parseFloat(dCapeTown.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempCapeTown').innerHTML = celciusCapeTown + '&deg;C';
	document.getElementById('locationCapeTown').innerHTML = dCapeTown.name;
}
//Lagos
function positionLagos( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramLagos(data);
	})
}
function paramLagos( dLagos ) {
  var celciusLagos = Math.round(parseFloat(dLagos.main.temp)-273.15);
	var fahrenheitLagos = Math.round(((parseFloat(dLagos.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempLagos').innerHTML = celciusLagos + '&deg;C';
	document.getElementById('locationLagos').innerHTML = dLagos.name;
}
//Casablanca
function positionCasablanca( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramCasablanca(data);
	})
}
function paramCasablanca( dCasablanca ) {
  var celciusCasablanca = Math.round(parseFloat(dCasablanca.main.temp)-273.15);
	var fahrenheitCasablanca = Math.round(((parseFloat(dCasablanca.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempCasablanca').innerHTML = celciusCasablanca + '&deg;C';
	document.getElementById('locationCasablanca').innerHTML = dCasablanca.name;
}
//RiodeJaneiro
function positionRiodeJaneiro( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramRiodeJaneiro(data);
	})
}
function paramRiodeJaneiro( dRiodeJaneiro ) {
  var celciusRiodeJaneiro = Math.round(parseFloat(dRiodeJaneiro.main.temp)-273.15);
	var fahrenheitRiodeJaneiro = Math.round(((parseFloat(dRiodeJaneiro.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempRiodeJaneiro').innerHTML = celciusRiodeJaneiro + '&deg;C';
	document.getElementById('locationRiodeJaneiro').innerHTML = dRiodeJaneiro.name;
}
//buenos
function positionBuenosAires( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramBuenosAires(data);
	})
}
function paramBuenosAires( dBuenosAires ) {
  var celciusBuenosAires = Math.round(parseFloat(dBuenosAires.main.temp)-273.15);
	var fahrenheitBuenosAires = Math.round(((parseFloat(dBuenosAires.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempBuenosAires').innerHTML = celciusBuenosAires + '&deg;C';
	document.getElementById('locationBuenosAires').innerHTML = dBuenosAires.name;
}
//mexico
function positionMexico( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramMexico(data);
	})
}
function paramMexico( dMexico ) {
  var celciusMexico = Math.round(parseFloat(dMexico.main.temp)-273.15);
	var fahrenheitMexico = Math.round(((parseFloat(dMexico.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempMexico').innerHTML = celciusMexico + '&deg;C';
	document.getElementById('locationMexico').innerHTML = dMexico.name;
}
//dallas
function positionDallas( cityID ) {
	fetch('https://api.openweathermap.org/data/2.5/weather?id=' + cityID + '&appid=4e79125c06f3e5e33258f5749d22989f')
	.then(function(resp) { return resp.json() }) 
	.then(function(data) {
		paramDallas(data);
	})
}
function paramDallas( dDallas ) {
  var celciusDallas = Math.round(parseFloat(dDallas.main.temp)-273.15);
	var fahrenheitDallas = Math.round(((parseFloat(dDallas.main.temp)-273.15)*1.8)+32);
	document.getElementById('tempDallas').innerHTML = celciusDallas + '&deg;C';
	document.getElementById('locationDallas').innerHTML = dDallas.name;
}

//output to screen
window.onload = function() {
	position( 2643743 );
	positionNY( 5128581 );
	positionBeijing( 1816670 );
	positionLA2 ( 5368361 );
	positionBUDA ( 3054643 );
	positionVienna ( 2761369);
	positionPrague (3067696);
	positionBerlin (2950159);
	positionParis (2988507);
	positionMadrid (3117735);
	positionBarcelona (3128760);
	positionLisbon (2267057);
	positionMoscow ( 524901 );
	positionIstanbul ( 745042 );
	positionlCairol (  360630);
	positionDubai ( 292223 );
	positionTehran ( 112931 );
	positionJerusalem ( 281184 );
	positionDelhi ( 1273294 );
	positionBangkok ( 1609350 );
	positionShanghai ( 1796236 );
	positionTokyo ( 1850144 );
	positionSydney ( 2147714 );
	positionCapeTown ( 3369157 );
	positionLagos ( 2332459 );
	positionCasablanca (2553604  );
	positionRiodeJaneiro ( 3451190 );
	positionBuenosAires ( 3435910 );
	positionMexico ( 3530597 );
	positionDallas ( 4684888 );
}
