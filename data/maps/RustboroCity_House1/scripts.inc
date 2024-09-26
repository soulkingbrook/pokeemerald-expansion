RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::

	// Check a flag to see if the trade has already happened
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted

	// Buffer the trade and requested POKéMON names and ask if you want to trade
	setvar VAR_0x8008, INGAME_TRADE_APPLIN
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade

	// Handle the selection of the requested POKéMON from the player
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon

	// Perform the actual trade
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate

	msgbox RustboroCity_House1_Text_GoodLuck, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_FineGoAwayThen, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_ThatIsntAMon, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_BugTypePokemonAreTheGreatest, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Yanma::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_YANMA, CRY_MODE_NORMAL
	msgbox RustboroCity_House1_Text_Yanma, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House1_EventScript_Wurmple::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WURMPLE, CRY_MODE_NORMAL
	msgbox RustboroCity_House1_Text_Wurmple, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House1_EventScript_Golisopod::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GOLISOPOD, CRY_MODE_NORMAL
	msgbox RustboroCity_House1_Text_Golisopod, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "I thought my {STR_VAR_2} was a BUG-type,\n"
	.string "but my friend lied.\p"
	.string "Hey, you're a TRAINER, right?\n"
	.string "Would you like to trade?\p"
	.string "If you want a POKéMON that'll be handy\n"
	.string "against ROXANNE, I'll trade you my\l"
	.string "{STR_VAR_2} for a {STR_VAR_1}.$"

RustboroCity_House1_Text_GoodLuck:
	.string "Eheheh…\n"
	.string "Good luck with the GYM.$"

RustboroCity_House1_Text_ThatIsntAMon:
	.string "That isn't a {STR_VAR_1}!\n"
	.string "Quit wasting my time, asshole!$"

RustboroCity_House1_Text_FineGoAwayThen:
	.string "Fine, go away then.$"

RustboroCity_House1_Text_BugTypePokemonAreTheGreatest:
	.string "BUG-type POKéMON are the greatest,\n"
	.string "aren't they?\p"
	.string "But they're completely useless\n"
	.string "against ROCK types.$"

RustboroCity_House1_Text_Yanma:
	.string "YANMA: Bzzzt!$"

RustboroCity_House1_Text_Wurmple:
	.string "WURMPLE: Meow?$"

RustboroCity_House1_Text_Golisopod:
	.string "GOLISOPOD: 'Sup?$"
