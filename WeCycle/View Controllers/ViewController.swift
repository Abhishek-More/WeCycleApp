//
//  ViewController.swift
//  UI Animation
//
//  Created by Abhishek More on 2/14/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit
import Alamofire

//var account: Account = Account(user: "fake@gmail.com", rank: "Novice Recycler", xp: 0)

class ViewController: UIViewController, UITextFieldDelegate {
    
    @IBOutlet var quoteText: UILabel!
    @IBOutlet var emailText: UITextField!
    @IBOutlet var emailLabel: UILabel!
    @IBOutlet var passwordText: UITextField!
    @IBOutlet var passwordLabel: UILabel!
    @IBOutlet var signUp: UIButton!
    @IBOutlet var forgotText: UILabel!
    @IBOutlet var bubble: UIImageView!
    @IBOutlet var signInReal: UIButton!
    @IBOutlet var titleText: UIImageView!
    @IBOutlet var signInUserbutton: UIButton!
    @IBOutlet var confirmLine: UIImageView!
    @IBOutlet var confirmLabel: UILabel!
    @IBOutlet var confirmText: UITextField!
    @IBOutlet var dontHaveButton: UIButton!
    @IBOutlet var haveButton: UIButton!
    
    var emailGest: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(emailUp))
    var passGest: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(passUp))
    var confirmGest: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(confirmUp))
    
    var left: Bool = true
    var emailTextUp: Bool = false
    var passTextUp: Bool = false
    var confirmTextUp: Bool = false
    
    func HideKeyboard() {
        
        let Tap:UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(dismissKeyboard))
        view.addGestureRecognizer(Tap)
        
    }
    
    @objc func dismissKeyboard () {
        view.endEditing(true)
        if((emailText.text == "" || emailText.text == nil) && emailTextUp) {
            UIView.animate(withDuration: 0.25) {
                
                self.emailLabel.transform = CGAffineTransform(scaleX: 1, y: 1)
                self.emailLabel.center.y += 25
                self.emailLabel.center.x += 5
                
            }
            emailTextUp = false
            emailGest.isEnabled = true
        }
        
        if((passwordText.text == "" || passwordText.text == nil) && passTextUp) {
            UIView.animate(withDuration: 0.25) {
                
                self.passwordLabel.transform = CGAffineTransform(scaleX: 1, y: 1)
                self.passwordLabel.center.y += 25
                self.passwordLabel.center.x += 5

            }

            passTextUp = false
            passGest.isEnabled = true
            
        }

        if((confirmText.text == "" || confirmText.text == nil) && confirmTextUp) {
            UIView.animate(withDuration: 0.25) {
                
                self.confirmLabel.transform = CGAffineTransform(scaleX: 1, y: 1)
                self.confirmLabel.center.y += 25
                self.confirmLabel.center.x += 5
                
            }
            
            confirmTextUp = false
            confirmGest.isEnabled = true
            
        }
    }
    
    func authenticate() {
        //authenticate Data
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.HideKeyboard()
    
        titleText.alpha =  0
        titleText.center.y -= 30
        quoteText.alpha = 0
        quoteText.center.y -= 30
        
        confirmLine.center.x += 400
        confirmText.center.x += 400
        confirmLabel.center.x += 400
        confirmLine.alpha = 0
        confirmText.alpha = 0
        confirmLabel.alpha = 0
        
        haveButton.alpha = 0
        
        
            UIView.animate(withDuration: 1) {
                
                self.titleText.center.y += 30
                self.quoteText.center.y += 30
                self.quoteText.alpha = 0.6
                self.titleText.alpha = 1
                
            }
        
        
        emailGest = UITapGestureRecognizer(target: self, action: #selector(emailUp))
        emailText.addGestureRecognizer(emailGest)
        
        passGest = UITapGestureRecognizer(target: self, action: #selector(passUp))
        passwordText.addGestureRecognizer(passGest)
        
        confirmGest = UITapGestureRecognizer(target: self, action: #selector(confirmUp))
        confirmText.addGestureRecognizer(confirmGest)

    }
    
    @objc func emailUp() {
        if(!emailTextUp) {
            UIView.animate(withDuration: 0.25) {
                
                self.emailLabel.center.y -= 25
                self.emailLabel.center.x -= 5
                self.emailLabel.transform = CGAffineTransform(scaleX: 9/10 , y: 9/10)
                
            }
            self.emailText.becomeFirstResponder()
            emailGest.isEnabled = false
            emailTextUp = true
        }
        
    }
    
    @objc func passUp() {
        if(!passTextUp) {
            UIView.animate(withDuration: 0.25) {
                
                self.passwordLabel.center.y -= 25
                self.passwordLabel.center.x -= 5
                self.passwordLabel.transform = CGAffineTransform(scaleX: 9/10 , y: 9/10)
                
            }
            
            self.passwordText.becomeFirstResponder()
            passGest.isEnabled = false
            passTextUp = true
            
        }
    }
    
    @objc func confirmUp() {
        if(!confirmTextUp) {
            UIView.animate(withDuration: 0.25) {
                
                self.confirmLabel.center.y -= 25
                self.confirmLabel.center.x -= 5
                self.confirmLabel.transform = CGAffineTransform(scaleX: 9/10 , y: 9/10)
                
            }
            self.confirmText.becomeFirstResponder()
            confirmGest.isEnabled = false
            confirmTextUp = true
        }
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        
        return true
        
    }
    
    func textFieldDidBeginEditing(_ textField: UITextField) {
        
        UIView.animate(withDuration: 0.25) {
            self.view.center.y -= 250
        }
        
        if(passwordText.isFirstResponder) {
            UIView.animate(withDuration: 0.5) {
                
                self.forgotText.alpha = 0
                
            }
            
        }
        
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        
        UIView.animate(withDuration: 0.25) {
            self.view.center.y += 250
        }
        
        if(passwordText.text == "") {
            
            UIView.animate(withDuration: 0.5) {
                
                self.forgotText.alpha = 1
                
            }
        }
        
    }
    
    @IBAction func signInTouched(_ sender: Any) {
        bubble.alpha = 0.5
        
    }
    
    @IBAction func signInRelease(_ sender: Any) {
        bubble.alpha = 1
    }
    
    @IBAction func signInClicked(_ sender: Any) {
        
        bubble.alpha = 1
        let username = emailText.text
        let password = passwordText.text
        
//      account.account(user: "bobsmith@gmail.com")
//        
//        let rawFilename = "/Users/abhishek/WeCycleApp/WeCycle/google-services.json"
//        let cStringFile = strdup(rawFilename)
//        let firebaseObject = UnsafeMutableRawPointer(mutating: initializeFirebase(cStringFile))
//
//        let databaseManagerObject = UnsafeMutableRawPointer(mutating: initializeDataManager(firebaseObject))
//
//        let authenticationObject = UnsafeMutableRawPointer(mutating: initializeAuthentication(firebaseObject, databaseManagerObject))
//
//        let account = UnsafeMutableRawPointer(mutating: initializeAccount(databaseManagerObject))
//
//        signInUser(authenticationObject, account, strdup(username), strdup(password))
//
//        DispatchQueue.main.asyncAfter(deadline: .now() + 3) {
//            updateRank(account)
//        }
//        
//        DispatchQueue.main.asyncAfter(deadline: .now() + 3) {
//            if(checkAccount(account)) {
//                self.performSegue(withIdentifier: "signInSegue", sender: self)
//                
//                let x: UnsafePointer<Int8> = rank(account)
//                print(String(cString: x))
//                
//            } else {
//                print("Account not valid")
//            }
//            
//        }
        
        performSegue(withIdentifier: "signInSegue", sender: self)

        
    }
    
    override var prefersStatusBarHidden: Bool {
        
        return true
        
    }
    
    @IBAction func signUpClick(_ sender: Any) {
        
        let username = emailText.text
        let password = passwordText.text

//
//        let rawFilename = "/Users/abhishek/WeCycleApp/WeCycle/google-services.json"
//        let cStringFile = strdup(rawFilename)
//        let firebaseObject = UnsafeMutableRawPointer(mutating: initializeFirebase(cStringFile))
//
//        let databaseManagerObject = UnsafeMutableRawPointer(mutating: initializeDataManager(firebaseObject))
//
//        let authenticationObject = UnsafeMutableRawPointer(mutating: initializeAuthentication(firebaseObject, databaseManagerObject))
//
//        let account = UnsafeMutableRawPointer(mutating: initializeAccount(databaseManagerObject))
//
//        createAndRegisterAccount(authenticationObject, account, strdup(username), strdup(password))
        
//        DispatchQueue.main.asyncAfter(deadline: .now() + 3) {
//            if(checkAccount(account)) {
//                self.performSegue(withIdentifier: "signInSegue", sender: self)
//            } else {
//                print("Account not valid")
//            }
//
//        }
        performSegue(withIdentifier: "signInSegue", sender: self)
        
        
    }
    
    @IBAction func newAccount(_ sender: Any) {
        
        UIView.animate(withDuration: 0.5) {
            self.confirmLine.center.x -= 400
            self.confirmText.center.x -= 400
            self.confirmLabel.center.x -= 400
            self.confirmLine.alpha = 1
            self.confirmText.alpha = 1
            self.confirmLabel.alpha = 0.6
            self.forgotText.alpha = 0
            self.haveButton.center.x -= 400
            self.dontHaveButton.center.x -= 400
            self.dontHaveButton.alpha = 0
            self.haveButton.alpha = 1
            self.signInReal.center.x -= 400
            self.signInReal.alpha = 0
            self.signInUserbutton.center.x -= 400
            self.signInUserbutton.alpha = 1
        
        }
        
        haveButton.isEnabled = true
        dontHaveButton.isEnabled = false
        
    }
    
    @IBAction func existingAccount(_ sender: Any) {
        
        UIView.animate(withDuration: 0.5) {
            self.confirmLine.center.x += 400
            self.confirmText.center.x += 400
            self.confirmLabel.center.x += 400
            self.confirmLine.alpha = 0
            self.confirmText.alpha = 0
            self.confirmLabel.alpha = 0
            self.forgotText.alpha = 1
            self.haveButton.center.x += 400
            self.dontHaveButton.center.x += 400
            self.dontHaveButton.alpha = 1
            self.haveButton.alpha = 0
            self.signInReal.center.x += 400
            self.signInReal.alpha = 1
            self.signInUserbutton.center.x += 400
            self.signInUserbutton.alpha = 0

        }
        
        haveButton.isEnabled = false
        dontHaveButton.isEnabled = true
        
    }
    
}
