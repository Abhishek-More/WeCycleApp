//
//  LeftScreenViewController.swift
//  WeCycle
//
//  Created by Abhishek More on 2/20/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit

class LeftScreenViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet var friendsCard: UIImageView!
    @IBOutlet var profileCard: UIImageView!
    @IBOutlet var rankText: UILabel!
    @IBOutlet var profileText: UILabel!
    @IBOutlet var topRect: UIImageView!
    @IBOutlet var profileHolder: UIView!
    @IBOutlet weak var containerView: UIView!
    @IBOutlet weak var coinText: UILabel!
    @IBOutlet weak var xpLabel: UILabel!
    let delegate = UIApplication.shared.delegate as! AppDelegate
    @IBOutlet var display: UILabel!
    @IBOutlet var popUp: UIView!
    @IBOutlet var emailField: UITextField!
    var del: LeftScreenDelegate?
    var friends: [UnsafeMutableRawPointer] = []
    
    @IBOutlet var tableViewRee: UITableView!
    
    
    var profileCenter: CGFloat = 0
    var friendsCenter: CGFloat = 0
    var topRectCenter: CGFloat = 0
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        
        popUp.center.x = view.center.x
        popUp.center.y = view.center.y + 700
        
        profileCenter = profileHolder.center.y
        friendsCenter = containerView.center.y
        topRectCenter = topRect.center.y

        
        
    }
    
    
    func swipeReaction(num: Double) {
        
        rankText.alpha = CGFloat(abs(1 - num / 125))
        profileText.alpha = CGFloat(abs(1 - num / 125))
        profileHolder.center.y = profileCenter - CGFloat(500 * abs((num / 375)))
        containerView.center.y = friendsCenter + CGFloat(500 * abs((num / 375)))
        topRect.center.y = topRectCenter - CGFloat(75 * abs((num / 375)))
        coinText.text = String(coins(delegate.account))
        xpLabel.text = String(experience(delegate.account)) + " XP"
        let rankString: UnsafePointer<Int8> = rank(delegate.account)
        rankText.text = String(cString: rankString)
        let displayString: UnsafePointer<Int8> = displayName(delegate.account)
        display.text = String(cString: displayString)

    }
    
    override var prefersStatusBarHidden: Bool {
        return true
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return friends.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell") as! FriendsTableViewCell

        let acc = friends[indexPath.row]

//        let displayString: UnsafePointer<Int8> = displayName(delegate.account)
       cell.nameLabel.text = "John Kim"
//
//        let rankString: UnsafePointer<Int8> = rank(delegate.account)
     cell.qualifierLabel.text = "EPA Agent"
//
        cell.xpLabel.text = "540 XP"
    return cell
        
        
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 60.0
    }
    @IBAction func addFriends(_ sender: Any) {
        self.view.addSubview(self.popUp)
        UIView.animate(withDuration: 0.5) {
           
            self.popUp.center = self.view.center
            self.del?.setScrolling(enabled: false)
            
        }
        
    }
    
    @IBAction func addFriend(_ sender: Any) {
        let rawFilename = "/Users/abhishek/WeCycleApp/WeCycle/google-services.json"
        let cStringFile = strdup(rawFilename)
        let firebaseObject = UnsafeMutableRawPointer(mutating: initializeFirebase(cStringFile))
        let databaseManagerObject = UnsafeMutableRawPointer(mutating: initializeDataManager(firebaseObject))
        let authenticationObject = UnsafeMutableRawPointer(mutating: initializeAuthentication(firebaseObject, databaseManagerObject))
        let account = UnsafeMutableRawPointer(mutating: initializeAccount(databaseManagerObject))
        signInUser(authenticationObject, account, strdup(emailField.text ?? "jkim@gmail.com"), strdup("password"))
        view.endEditing(true)
        //let experience = experience(account)
        DispatchQueue.main.asyncAfter(deadline: .now() + 4) {
            
            self.closeFriendPopup(5)
            self.friends.append(account!)
            self.tableViewRee.reloadData()
            
        }
    }
    
    @IBAction func closeFriendPopup(_ sender: Any) {
        self.del?.setScrolling(enabled: true)
        
        UIView.animate(withDuration: 0.5, animations: {
            self.popUp.center.y += 700
        }) { (_) in
            self.popUp.removeFromSuperview()
        }
        
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        view.endEditing(true)
    }
    
}

