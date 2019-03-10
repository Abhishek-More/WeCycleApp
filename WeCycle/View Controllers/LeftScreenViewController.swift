//
//  LeftScreenViewController.swift
//  WeCycle
//
//  Created by Abhishek More on 2/20/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit

class LeftScreenViewController: UIViewController {
    
    @IBOutlet var friendsCard: UIImageView!
    @IBOutlet var profileCard: UIImageView!
    @IBOutlet var rankText: UILabel!
    @IBOutlet var profileText: UILabel!
    @IBOutlet var circle: UIImageView!
    @IBOutlet var topRect: UIImageView!
    @IBOutlet var profileHolder: UIView!
    
    var profileCenter: CGFloat = 0
    var friendsCenter: CGFloat = 0
    var topRectCenter: CGFloat = 0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        profileCenter = profileHolder.center.y
        friendsCenter = friendsCard.center.y
        topRectCenter = topRect.center.y
        
    }
    
    
    
    func swipeReaction(num: Double) {
        
        rankText.alpha = CGFloat(abs(1 - num / 125))
        profileText.alpha = CGFloat(abs(1 - num / 125))
        profileHolder.center.y = profileCenter - CGFloat(500 * abs((num / 375)))
        friendsCard.center.y = friendsCenter + CGFloat(500 * abs((num / 375)))
        topRect.center.y = topRectCenter - CGFloat(75 * abs((num / 375)))

    }
    
    func shrink() {
        
        UIView.animate(withDuration: 0.25) {
            self.circle.transform = CGAffineTransform(scaleX: 1, y: 1)
        }
    }
    
    @IBAction func profileClick(_ sender: Any) {
        
        UIView.animate(withDuration: 0.5) {
            self.circle.transform = CGAffineTransform(scaleX: 15, y: 15)
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
            self.performSegue(withIdentifier: "settingsSegue", sender: self)
        }
        
    }
    override var prefersStatusBarHidden: Bool {
        return true
    }

}

