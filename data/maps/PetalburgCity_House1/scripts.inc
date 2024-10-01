PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Man::
	msgbox PetalburgCity_House1_Text_TravellingIsWonderful, MSGBOX_NPC
	end

PetalburgCity_House1_EventScript_Hydrapple::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HYDRAPPLE, CRY_MODE_NORMAL
	msgbox PetalburgCity_House1_Text_YumYumYum, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PetalburgCity_House1_EventScript_Youngster::
	msgbox PetalburgCity_House1_Text_GiantMonster, MSGBOX_NPC
	end

PetalburgCity_House1_Text_TravellingIsWonderful:
	.string "Hahaha!\p"
	.string "When I was young, I had a wild\n"
	.string "imagination, too!\l"
	.string "It's how I met my late wife!\p"
	.string "'Course, dementia took that away, too…$"

PetalburgCity_House1_Text_YumYumYum:
	.string "HYDRAPPLE: Yum, yum, yum…$"

PetalburgCity_House1_Text_GiantMonster:
	.string "Run while you still can!\p"
	.string "Grandpa's HYDRAPPLE is on the loose! It\n"
	.string "has a taste for the blood of virgins!$"

