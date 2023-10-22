import random

class card:
    def __init__(self,rank,suit):
        self.rank=rank
        self.suit=suit

class deck:
    def __init__(self):
        suits = ['Hearts','Diamonds','Clubs','Spades']
        ranks = [2,3,4,5,6,7,8,9,10,'J','Q','K','A']
        self.cards=[card(rank,suit) for rank in ranks for suit in suits]
    
    def shuffle(self):
        random.shuffle(self.cards)

    def isPair(self,card1,card2):
        ranks = [2,3,4,5,6,7,8,9,10,'J','Q','K','A']
        dic={rank: i for i, rank in enumerate(ranks)}
        diff=(dic[card1.rank]-dic[card2.rank])% len(ranks)
        return diff in[0,1,len(ranks)-1]
    
deck=deck()
deck.shuffle()

for card in deck.cards:
    print(f'{card.rank} of {card.suit}')

pair={}

for i in range(len(deck.cards)-1):
    card1 = deck.cards[i]
    card2 = deck.cards[i+1]
    if deck.isPair(card1, card2):
        pair[f'{card1.rank} of {card1.suit}'] = f'{card2.rank} of {card2.suit}'

print("\n\nPairs:\n")
for p,q in pair.items():
    print(p,"and",q)