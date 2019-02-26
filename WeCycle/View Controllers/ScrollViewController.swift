//
//  ScrollViewController.swift
//  WeCycle
//
//  Created by Abhishek More on 2/20/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit

class ScrollViewController: UIViewController, UIViewControllerTransitioningDelegate, UIScrollViewDelegate {

    @IBOutlet var cameraButton: UIButton!
    
    @IBOutlet var scrollView: UIScrollView!
    
    var middle: CameraViewController!
    var left = false
    var right = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        scrollView.delegate = self
        
        let left = self.storyboard?.instantiateViewController(withIdentifier: "left") as! LeftScreenViewController
        self.addChild(left)
        self.scrollView.addSubview(left.view)
        self.didMove(toParent: self)
        
        middle = self.storyboard?.instantiateViewController(withIdentifier: "middle") as! CameraViewController
        self.addChild(middle)
        self.scrollView.addSubview(middle.view)
        self.didMove(toParent: self)
        
        var middleFrame: CGRect = middle.view.frame
        middleFrame.origin.x = self.view.frame.width
        middle.view.frame = middleFrame
        
        let right = self.storyboard?.instantiateViewController(withIdentifier: "right") as! RightScreenViewController
        self.addChild(right)
        self.scrollView.addSubview(right.view)
        self.didMove(toParent: self)
        
        var rightFrame: CGRect = right.view.frame
        rightFrame.origin.x = 2 * self.view.frame.width
        right.view.frame = rightFrame
        
        self.scrollView.contentSize = CGSize(width: (self.view.frame.width) * 3 , height: (self.view.frame.height))
        scrollView.contentOffset.x = view.frame.width
        
        print(scrollView.contentOffset.x)

    }
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        middle.blurring(num: Double(scrollView.contentOffset.x))
    }
    
    
    @IBAction func cameraButtonPressed(_ sender: Any) {
        
        UIScrollView.animate(withDuration: 0.5) {
            self.scrollView.contentOffset.x = self.view.frame.width
        }
        
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
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

