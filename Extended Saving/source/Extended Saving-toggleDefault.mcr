macroScript toggleDefault category:"Extended Saving" tooltip:"Ignore Me"
(
	on execute do
	(
		local tokenMenu = menuMan.findMenu "Extended Saving By Default"
		if tokenMenu == undefined then menuman.createMenu "Extended Saving By Default"
		else menuman.unRegisterMenu tokenMenu
	)
	on isVisible do
	(
		local menuItem = ( ( menuMan.findMenu "Extended Saving" ).getItem 2 )
		if ( menuMan.findMenu "Extended Saving By Default" ) != undefined then menuItem.setTitle "Default: Enabled"
		else menuItem.setTitle "Default: Disabled"
		return true	
	)
) 