def nim_game(piles):
    nim_sum = 0
    for pile in piles:
        nim_sum ^= pile
    return nim_sum != 0


def test_nim_game():
    piles = [10, 12, 5]
    assert nim_game(piles) == True


if __name__ == "__main__":
    test_nim_game()
    print("Everything passed")
