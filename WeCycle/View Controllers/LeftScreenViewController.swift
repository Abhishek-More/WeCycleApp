//
//  LeftScreenViewController.swift
//  WeCycle
//
//  Created by Abhishek More on 2/20/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit
import WebKit
import AVFoundation

class LeftScreenViewController: UIViewController, UIViewControllerTransitioningDelegate, UICollectionViewDelegate, UICollectionViewDataSource {
    

    
    @IBOutlet var blueCard: UIImageView!
    @IBOutlet var collectionView: UICollectionView!
    @IBOutlet var menuButton: UIButton!
    @IBOutlet var username: UILabel!
    
    var usernameCenter: CGFloat = 0
    var blueCardCenter: CGFloat = 0
    var collectCenter: CGFloat = 0

    
    let transition = CircularTransition()
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        usernameCenter = username.center.y
        blueCardCenter = blueCard.center.y
        collectCenter = collectionView.center.y
        
        menuButton.layer.cornerRadius = menuButton.frame.size.width / 2
        collectionView.reloadData()
        
    }
    
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let secondVC = segue.destination as! StatsViewController
        secondVC.transitioningDelegate = self
        secondVC.modalPresentationStyle = .custom
    }
    
    func animationController(forPresented presented: UIViewController, presenting: UIViewController, source: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        transition.transitionMode = .present
        transition.startingPoint = menuButton.center
        transition.circleColor = menuButton.backgroundColor!
        
        return transition

    }
    
    func animationController(forDismissed dismissed: UIViewController) -> UIViewControllerAnimatedTransitioning? {
        transition.transitionMode = .dismiss
        transition.startingPoint = menuButton.center
        transition.circleColor = menuButton.backgroundColor!
        
        return transition
        
    }
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 3
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "NewsCell", for: indexPath) as! NewsCollectionViewCell
        cell.card.image = UIImage(named: "News Card")
        return cell
        
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        
        performSegue(withIdentifier: "newsSegue", sender: self)
        
    }
    
    func swipeReaction(num: Double) {
        
        self.blueCard.center.y = blueCardCenter - CGFloat(300 * (num / 375))
        self.username.center.y = usernameCenter - CGFloat(300 * (num/375))
        self.collectionView.center.y = collectCenter + CGFloat(300 * (num / 375))
        
    }
    
    override func viewDidAppear(_ animated: Bool) {
        
        print("yes")
        
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        
        print("no")
        
    }

}

