.set LOCALID_GUARDTOT, 8

FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox Chillage_Text_Sign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox Chillage_Text_GymSign, MSGBOX_SIGN
	end

Chillage_EventScript_CheckParty0::
	lockall
	setvar VAR_0x8008, 0
	ballfollowingmon
	goto Chillage_EventScript_GuardtotCheck
	end

Chillage_EventScript_CheckParty1::
	lockall
	setvar VAR_0x8008, 1
	ballfollowingmon
	goto Chillage_EventScript_GuardtotCheck
	end

Chillage_EventScript_CheckParty2::
	lockall
	setvar VAR_0x8008, 2
	ballfollowingmon
	goto Chillage_EventScript_GuardtotCheck
	end

Chillage_EventScript_CheckParty3::
	lockall
	setvar VAR_0x8008, 3
	ballfollowingmon
	goto Chillage_EventScript_GuardtotCheck
	end

Chillage_EventScript_Guardtot::
	lock
	faceplayer
	goto_if_set FLAG_SHOWED_FLYING_TYPE_CHATOT, Chillage_EventScript_GuardtotHaveFlying
	waitse
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	msgbox Chillage_Text_GuardtotDorahoo, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Chillage_EventScript_GuardtotCheck::
	applymovement LOCALID_GUARDTOT, Common_Movement_FacePlayer
	waitmovement 0
	playSE SE_PIN
	applymovement LOCALID_GUARDTOT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GUARDTOT, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 0, Chillage_EventScript_GuardtotApproach0
	call_if_eq VAR_0x8008, 1, Chillage_EventScript_GuardtotApproach1
	call_if_eq VAR_0x8008, 2, Chillage_EventScript_GuardtotApproach2
	call_if_eq VAR_0x8008, 3, Chillage_EventScript_GuardtotApproach3
	msgbox Chillage_Text_GuardtotHalt, MSGBOX_DEFAULT
	special IsFlyingTypeInParty
	goto_if_eq VAR_RESULT, FALSE, Chillage_EventScript_GuardtotNoFlying
	msgbox Chillage_Text_GuardtotChooray, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, Chillage_EventScript_GuardtotRetreat0
	call_if_eq VAR_0x8008, 1, Chillage_EventScript_GuardtotRetreat1
	call_if_eq VAR_0x8008, 2, Chillage_EventScript_GuardtotRetreat2
	call_if_eq VAR_0x8008, 3, Chillage_EventScript_GuardtotRetreat3
	setflag FLAG_SHOWED_FLYING_TYPE_CHATOT
	setvar VAR_FORTREE_CITY_STATE, 1
	msgbox Chillage_Text_GuardtotGreatJoy, MSGBOX_DEFAULT
	release
	end

Chillage_EventScript_GuardtotApproach0:
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotApproach0
	waitmovement 0
	return

Chillage_Movement_GuardtotApproach0:
	walk_right
	walk_down
	face_left
	step_end

Chillage_EventScript_GuardtotApproach1:
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotApproach1
	waitmovement 0
	return

Chillage_Movement_GuardtotApproach1:
	walk_right
	walk_down
	walk_down
	face_left
	step_end

Chillage_EventScript_GuardtotApproach2:
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotApproach2
	waitmovement 0
	return

Chillage_Movement_GuardtotApproach2:
	walk_right
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Chillage_EventScript_GuardtotApproach3:
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotApproach3
	waitmovement 0
	return

Chillage_Movement_GuardtotApproach3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Chillage_EventScript_GuardtotHaveFlying::
	msgbox Chillage_Text_GuardtotGreatJoy, MSGBOX_DEFAULT
	release
	end

Chillage_EventScript_GuardtotNoFlying::
	msgbox Chillage_Text_GuardtotPleaseLeave, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, Chillage_EventScript_GuardtotFailed0
	call_if_eq VAR_0x8008, 1, Chillage_EventScript_GuardtotFailed1
	call_if_eq VAR_0x8008, 2, Chillage_EventScript_GuardtotFailed2
	call_if_eq VAR_0x8008, 3, Chillage_EventScript_GuardtotFailed3
	release
	end

Chillage_EventScript_GuardtotFailed0::
	applymovement OBJ_EVENT_ID_PLAYER, Chillage_Movement_PlayerFailed
	waitmovement 0
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotReturn0
	waitmovement 0
	return

Chillage_EventScript_GuardtotFailed1::
	applymovement OBJ_EVENT_ID_PLAYER, Chillage_Movement_PlayerFailed
	waitmovement 0
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotReturn1
	waitmovement 0
	return

Chillage_EventScript_GuardtotFailed2::
	applymovement OBJ_EVENT_ID_PLAYER, Chillage_Movement_PlayerFailed
	waitmovement 0
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotReturn2
	waitmovement 0
	return

Chillage_EventScript_GuardtotFailed3::
	applymovement OBJ_EVENT_ID_PLAYER, Chillage_Movement_PlayerFailed
	waitmovement 0
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotReturn3
	waitmovement 0
	return

Chillage_EventScript_GuardtotRetreat0::
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotReturn0
	waitmovement 0
	return

Chillage_EventScript_GuardtotRetreat1::
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotReturn1
	waitmovement 0
	return

Chillage_EventScript_GuardtotRetreat2::
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotReturn2
	waitmovement 0
	return

Chillage_EventScript_GuardtotRetreat3::
	applymovement LOCALID_GUARDTOT, Chillage_Movement_GuardtotReturn3
	waitmovement 0
	return

Chillage_Movement_PlayerFailed:
	walk_fast_left
	step_end

Chillage_Movement_GuardtotReturn0:
	walk_up
	walk_left
	face_down
	step_end

Chillage_Movement_GuardtotReturn1:
	walk_up
	walk_up
	walk_left
	face_down
	step_end

Chillage_Movement_GuardtotReturn2:
	walk_up
	walk_up
	walk_up
	walk_left
	face_down
	step_end

Chillage_Movement_GuardtotReturn3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_down
	step_end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "No one believes me, but I saw this\n"
	.string "gigantic POKéMON in the sky.\p"
	.string "It seemed to squirm as it flew toward\n"
	.string "ROUTE 131.\p"
	.string "By the way… Sniff…\n"
	.string "Um… You, uh… smell singed.\p"
	.string "Were you at a volcano or something?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "I want to go to the POKéMON GYM,\n"
	.string "but something's blocking the way.\p"
	.string "After all the bother I went through\n"
	.string "training on ROUTE 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "I've got my pride-and-joy POKéMON\n"
	.string "with me. This time, I'll beat WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "The ground absorbs rainwater, and\n"
	.string "trees grow by drinking that water…\p"
	.string "Our FORTREE CITY exists because\n"
	.string "there's both water and soil.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "The CITY consists of homes built on\n"
	.string "trees.\p"
	.string "Perhaps because of that lifestyle,\n"
	.string "everyone is healthy and lively.\p"
	.string "Why, even myself--I feel as if I've\n"
	.string "grown thirty years younger.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Living on top of trees is okay.\p"
	.string "But sometimes BUG POKéMON come in\n"
	.string "through windows.\l"
	.string "It can be really startling.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "There are POKéMON that evolve when\n"
	.string "you trade them! That's what I heard.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Something unseeable is in the way.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON fled!$"

Chillage_Text_Sign:
	.string "CHATOT VILLAGE (CHILLAGE)\n"
	.string "“A safe haven for feathered friends.\l"
	.string "Formerly FORTREE CITY.”$"

Chillage_Text_GymSign:
	.string "CHATOT VILLAGE POKéMON GYM\n"
	.string "LEADER: WINONA\p"
	.string "“The bird user taking flight into\n"
	.string "the world.”$"

Chillage_Text_GuardtotHalt:
	.string "GUARDTOT: Halt!\p"
	.string "You must have at least one FLYING-type\n"
	.string "POKéMON to enter.$"

Chillage_Text_GuardtotGreatJoy:
	.string "GUARDTOT: I find great joy in having\n"
	.string "power over people, hence why I'm a cop.$"

Chillage_Text_GuardtotPleaseLeave:
	.string "Please leave.$"

Chillage_Text_GuardtotChooray:
	.string "… … … … … … … … … …\p"
	.string "CHOORAY!\p"
	.string "Alright, welcome to our chommunity.\n"
	.string "(That means “CHATOT community”!)$"

Chillage_Text_GuardtotDorahoo:
	.string "GUARDTOT: Dorahoo!$"

