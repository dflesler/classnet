document.documentElement.className='js';

function email(name, domain){
	var mail = name + '@' + domain + '.com';
	document.write('<a href="mailto:'+mail+'">'+mail+'</a>');
}