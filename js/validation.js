(function(){
	
	var c = $('country');
	c.onchange = function(){ 
		$('provinceItem').style.display = selectValue(c) === 'Argentina' ? 'block' : 'none';
	};
	c.onchange();
	
	var form = document.getElementsByTagName('form')[0];
	if (!form)
		return;
	
	var isIE = !!document.all,
		labels = form.getElementsByTagName('label'),
		cookies = {},
		submit = $('submit'),
		sent;
	
	submit.onclick = validate;
	
	for (var i=0, cs=document.cookie.split(/; ?/); i < cs.length; i++){
		var cookie = cs[i].split('=');
		cookies[decode(cookie[0])] = decode(cookie[1]);
	}
	
	forEach(function(label, id){
		if (cookies[id])
			$(id).value = cookies[id];
	});
	
	function decode(s){
		return decodeURIComponent(s);
	}
	
	function $(id){ 
		return document.getElementById(id); 
	}
	
	function selectValue(s){
		return s.options[s.selectedIndex].value;
	}
	
	function forEach(fn){
		for (var i=0; i < labels.length; i++)
			fn(labels[i], labels[i].htmlFor);
	}
	
	function validate(){
		var allOk = true;
		
		forEach(function(label, id){
			if (label.innerHTML.indexOf('*') === -1)
				return;
			
			var elem = $(id),
				ok = !!( elem.options ? selectValue(elem) : elem.value );
			allOk = allOk && ok;
			label.className = ok ? '' : 'error';
		});
		
		if (allOk && !isIE)
			submit.disabled = true;

		return allOk;
	}
})();

