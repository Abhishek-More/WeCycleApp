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
    var rank: Int = 0
    var xp: Int = 0
    
    init(user: String, rank: Int, xp: Int) {
        email = user
        self.rank = rank
        self.xp = xp
        
    }

    func account(user: String) {
        
        email = user
        rank = 0
        xp = 0
        
    }
    
    func updateRank(num: Int) {
        rank += num
    }
    
    func updateXP(num: Int) {
        xp += num
    }
    
    func getRank() -> Int {
        return rank
    }
    
    func getXP() -> Int {
        return xp
    }
    
    func getEmail() -> String {
        return email
    }
    
    
}
