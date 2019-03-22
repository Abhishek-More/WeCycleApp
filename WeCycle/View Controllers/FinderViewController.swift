//
//  FinderViewController.swift
//  WeCycle
//
//  Created by Abhishek More on 3/13/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit



class FinderViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet var tableView: UITableView!
    @IBOutlet var searchField: UITextField!
    @IBOutlet var searchButt: UIButton!
    
    
    
    var array: [Account] = []
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return array.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "friendsCell") ?? UITableViewCell(style: .default, reuseIdentifier: "default")
        
        return cell
        
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
    
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let account1 = Account.init(user: "bob@gmail.com", rank: "EPA Agent", xp: 670)
        
        let account2 = Account.init(user: "sherry@gmail.com", rank: "EPA Agent", xp: 560)
        
        array.append(account1)
        array.append(account2)
        

        
    }
    @IBAction func searchButtClicked(_ sender: Any) {
        
        let rawFilename = "/Users/abhishek/WeCycleApp/WeCycle/google-services.json"
        let cStringFile = strdup(rawFilename)
        let firebaseObject = UnsafeMutableRawPointer(mutating: initializeFirebase(cStringFile))
        let databaseManagerObject = UnsafeMutableRawPointer(mutating: initializeDataManager(firebaseObject))
        let authenticationObject = UnsafeMutableRawPointer(mutating: initializeAuthentication(firebaseObject, databaseManagerObject))
        let account = UnsafeMutableRawPointer(mutating: initializeAccount(databaseManagerObject))
        
        signInUser(authenticationObject, account, searchField.text, "password")
        DispatchQueue.main.asyncAfter(deadline: .now() + 4) {
        
            print(coins(account))
            
        }
        
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        view.endEditing(true)
    }
}
