//
//  Account.swift
//  WeCycle
//
//  Created by Abhishek More on 3/13/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import Foundation

class Account{

    var email: String = ""
    var rank: String = ""
    var xp: Int = 0
    var friends: [Account] = []
    
    init(user: String, rank: String, xp: Int) {
        email = user
        self.rank = rank
        self.xp = xp
    }

    func account(user: String) {
        
        email = user
        rank = "Novice Recycler"
        xp = 0
        
    }
    
    func updateFriends(friend: Account) {
        friends.append(friend)
    }
    
    func updateRank(num: String) {
        rank = num
    }
    
    func updateXP(num: Int) {
        xp += num
    }
    
    func getRank() -> String {
        return rank
    }
    
    func getXP() -> Int {
        return xp
    }
    
    func getEmail() -> String {
        return email
    }
    
    func getFriends() -> [Account] {
        return friends
    }
    
    
}
