def create_and_modify_dict():
    sports_teams = {
        "Buffalo Sabres": "Hockey",
        "Toronto Maple Leafs": "Hockey",
        "Boston Bruins": "Hockey",
        "Ottawa Senators": "Hockey",
        "Montreal Canadiens": "Hockey"
    }

    for key, value in sports_teams.items():
        print(f"{key}, {value}", end=", ")
    print()

    sports_teams["Toronto Maple Leafs"] = "Ice Hockey"
    for key, value in sports_teams.items():
        print(f"{key}, {value}", end=", ")
    print()

    del sports_teams["Ottawa Senators"]
    for key, value in sports_teams.items():
        print(f"{key}, {value}", end=", ")
    print()

    print()

    for key in sports_teams.keys():
        print(key)

    print()

    for value in sports_teams.values():
        print(value)

def main():
    create_and_modify_dict()

if __name__ == "__main__":
    main()
