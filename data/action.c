Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-GB,en;q=0.9");

	web_url("pets.shaft.com", 
		"URL=http://pets.shaft.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	lr_think_time(8);

	lr_start_transaction("Pets_Launch");

	web_url("Home", 
		"URL=http://pets.shaft.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Pets_Launch",LR_AUTO);

	lr_think_time(21);

	lr_start_transaction("Pets_FindOwner");

	web_url("Find owners", 
		"URL=http://pets.shaft.com/owners/find", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Pets_FindOwner",LR_AUTO);

	lr_start_transaction("Pets_SearchWithLastName");

	web_submit_data("owners", 
		"Action=http://pets.shaft.com/owners", 
		"Method=GET", 
		"EncType=", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners/find", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=lastName", "Value=arjun8181", ENDITEM, 
		LAST);

	lr_end_transaction("Pets_SearchWithLastName",LR_AUTO);

	lr_think_time(19);

	lr_start_transaction("Pets_AddNewPet");

	web_url("Add New Pet", 
		"URL=http://pets.shaft.com/owners/475603/pets/new", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners/475603", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Pets_AddNewPet",LR_AUTO);

	lr_start_transaction("Pets_GivePetDetails");

	web_submit_data("new", 
		"Action=http://pets.shaft.com/owners/475603/pets/new", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners/475603/pets/new", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=id", "Value=", ENDITEM, 
		"Name=name", "Value=allu_pet", ENDITEM, 
		"Name=birthDate", "Value=2024-01-11", ENDITEM, 
		"Name=type", "Value=dog", ENDITEM, 
		LAST);

	lr_end_transaction("Pets_GivePetDetails",LR_AUTO);

	return 0;
}