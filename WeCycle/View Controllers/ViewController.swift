//
//  ViewController.swift
//  UI Animation
//
//  Created by Abhishek More on 2/14/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit
import Alamofire

class ViewController: UIViewController {
    
    @IBOutlet var background: UIImageView!
    @IBOutlet var titleText: UILabel!
    @IBOutlet var quoteText: UILabel!
    @IBOutlet var bottomRect: UIImageView!
    @IBOutlet var emailText: UITextField!
    @IBOutlet var emailLabel: UILabel!
    @IBOutlet var passwordText: UITextField!
    @IBOutlet var passwordLabel: UILabel!
    @IBOutlet var signUp: UIButton!
    @IBOutlet var signIn: UIButton!
    @IBOutlet var signInText: UILabel!
    @IBOutlet var signUpText: UILabel!
    @IBOutlet var forgotText: UILabel!
    @IBOutlet var confirmLine: UIImageView!
    @IBOutlet var confirmText: UITextField!
    @IBOutlet var confirmLabel: UILabel!
    @IBOutlet var bubble: UIImageView!
    
    @IBOutlet var SignUpReal: UIButton!
    @IBOutlet var signInReal: UIButton!
    
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
    
        bottomRect.center.y -= 400
        background.center.y -= 400
        quoteText.alpha = 0
        quoteText.center.y -= 30
        titleText.alpha = 0
        titleText.center.y -= 30
        signUpText.alpha = 0
        
        UIView.animate(withDuration: 1.5) {
            
            self.bottomRect.center.y += 400
            self.background.center.y += 400
            
        }
        DispatchQueue.main.asyncAfter(deadline: .now() + 1.5) {
            UIView.animate(withDuration: 1) {
                
                self.titleText.center.y += 30
                self.quoteText.center.y += 30
                self.quoteText.alpha = 0.6
                self.titleText.alpha = 1
                
            }
        }
        emailGest = UITapGestureRecognizer(target: self, action: #selector(emailUp))
        emailText.addGestureRecognizer(emailGest)
        
        passGest = UITapGestureRecognizer(target: self, action: #selector(passUp))
        passwordText.addGestureRecognizer(passGest)
        
        confirmGest = UITapGestureRecognizer(target: self, action: #selector(confirmUp))
        confirmText.addGestureRecognizer(confirmGest)
        
        // Do any additional setup after loading the view, typically from a nib.
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
    
    @IBAction func Left(_ sender: Any) {
        if(!left){
            
            UIView.animate(withDuration: 0.75) {
                
                self.background.center.x += 50
                self.signUp.center.x += 400
                self.signIn.center.x += 400
                self.signUpText.center.x += 105
                self.signUpText.alpha = 0
                self.signInText.center.x += 105
                self.signInText.alpha = 1
                self.forgotText.center.x += 400
                self.confirmLabel.center.x += 400
                self.confirmText.center.x += 400
                self.confirmLine.center.x += 400
                self.SignUpReal.center.x += 400
                self.signInReal.center.x += 400
                self.forgotText.alpha = 1
                
            }
            
            left = true
        }
        
    }
    
    @IBAction func right(_ sender: Any) {
        
        if(left){
            
            UIView.animate(withDuration: 0.75) {
                
                self.background.center.x -= 50
                self.signUp.center.x -= 400
                self.signIn.center.x -= 400
                self.signInText.center.x -= 105
                self.signInText.alpha = 0
                self.signUpText.center.x -= 105
                self.signUpText.alpha = 1
                self.forgotText.center.x -= 400
                self.forgotText.alpha = 0
                self.confirmLabel.center.x -= 400
                self.confirmText.center.x -= 400
                self.confirmLine.center.x -= 400
                self.SignUpReal.center.x -= 400
                self.signInReal.center.x -= 400
                
            }
            
            left = false
            
        }
        
    }
    
    @IBAction func signInTouched(_ sender: Any) {
        bubble.alpha = 0.5
        
    }
    
    @IBAction func signInRelease(_ sender: Any) {
        bubble.alpha = 1
    }
    
    @IBAction func signUpTouched(_ sender: Any) {
        bubble.alpha = 0.5
    }
    
    @IBAction func singUpRelease(_ sender: Any) {
        bubble.alpha = 1
    }
    
    @IBAction func signInClicked(_ sender: Any) {
        
        bubble.alpha = 1
        
        
        
        

        UIView.animate(withDuration: 1) {
            self.view.center.y -= 800
        }
        
        
        
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 1.2) {
            self.performSegue(withIdentifier: "signInSegue", sender: self)
        }
        
//                UIView.animate(withDuration: 0.25) {
//                    self.titleText.alpha = 0
//                    self.quoteText.alpha = 0
//                    self.emailText.alpha = 0
//                    self.emailLabel.alpha = 0
//                    self.bubble.alpha = 0
//                    self.passwordText.alpha = 0
//                    self.passwordLabel.alpha = 0
//                           
//               }
        
    }
    @IBAction func signUpClicked(_ sender: Any) {
        
        if(emailText.text != "" || passwordText.text != "") {
            
            if(passwordText.text == confirmText.text) {
            let username = emailText.text
            let password = passwordText.text


            let rawFilename = "/Users/abhishek/Desktop/TestApps/WeCycle/WeCycle/google-services.json"
            let cStringFile = strdup(rawFilename)
            let firebaseObject = UnsafeMutableRawPointer(mutating: initializeFirebase(cStringFile))


            //let authenticationObject = UnsafeMutableRawPointer(mutating: initializeAuthentication(firebaseObject))
            //createAndRegisterAccount_string(authenticationObject, strdup(username), strdup(password))
            
            DispatchQueue.main.asyncAfter(deadline: .now() + 1.2) {
                
                    self.performSegue(withIdentifier: "signInSegue", sender: self)
                
            }
                
            } else {
                
                print("Password does not match")
                
            }
            
            //let array : [String] = retrieveData(databaseManagerObject, "Accounts", "email@gmail.com")
        
    }
    
}

}
