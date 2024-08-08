# Development Quandries

This project has lead to a lot of quite interesting questions. 

## What categories of objects should we have?
Obviously, the atomic unit of cards games is the card. And the in most scenarios their maximal grouping is that of a deck, necessitating the creation of at least two objects:
Cards -> decks?
What about hands, or partial decks like in games?
This requires the insertion of another layer:
cards->card sets -> decks
What about games like Pounce with multiple decks?
Cards -> cardSets -> Decks -> multiDecks

### Notable edge case: Multi-Deck games
How should multi-decks be handled? It would depend on if cards might have to know which deck they belong to? 
One the one hand this could exist as a field on the card object, but that would be a rather specific use case. The second option is composing the card into a "multideck card" object that has an additional const "deck" variable. 


## How should card memory be handled?
One option is to regularly destroy, and and remove copies of cards. On the one hand this makes sense from the scope of a given hand. Cards are added and destroyed and don't exist outisde of that. This is also, in many cases, syntactically simpler in C++. But from the scope of card games, cards change location but are neither created nor destroyed in the course of play. The full set ought to exist at all times with in the context of a game. Implementing the cards as created only once, and passing pointers back and forth is syntactically more difficult, it should reduce memory issues and card disappearance errors. 

### Possible future ventures
Implementing a code analysis tool to ensure that card pointers are not lost in the course of the game would be an interesting future problem. It would likely be similar to a reference-counter in a garbage-collecting language, and thus much of those algorithms have already been implemented. 
This is quite a different problem from the compiler and programs plan to get rid of or erase unused data. Is it worth building my own tooling/reference counter to check that data is still accessible?
- This tool would likely do code checking insertion to check after every card use and reference that it was still accessible from within the data structure. This would likely work as a compiler preprocessing step.

In addition, many ooperations will eventually require working with sets of cards. Should a hand or card-stack be creatable by being passed a set, or should add and remove operations be able to manage sets of cards? This would support dealing, draw operations, and adding operations. 

Is it worth implementing a cardset as its own class, or simply having a built in set convention like a list or vector?


Should I instead have used some sort of inheritance?
Hands and Decks are both "card sets", with shuffle, sort, add/delete one/many operations. 