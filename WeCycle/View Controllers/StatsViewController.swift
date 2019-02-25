//
//  AccountViewController.swift
//  WeCycle
//
//  Created by Abhishek More on 2/21/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit

class StatsViewController: UIViewController {

    
    @IBOutlet var dismissButton: UIButton!
    @IBOutlet var titleText: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
//        titleText.center.x += 100
//        titleText.alpha = 0
//        
//        UIView.animate(withDuration: 0.5) {
//            
//            self.titleText.alpha = 1
//            self.titleText.center.x = -100
//            
//        }

        dismissButton.layer.cornerRadius = dismissButton.frame.size.width / 2
  
    }
    
    

    @IBAction func dismissView(_ sender: Any) {
        
        self.dismiss(animated: true, completion: nil)
        
    }
    
    
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
