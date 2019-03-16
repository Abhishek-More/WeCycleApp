//
//  RightScreenViewController.swift
//  WeCycle
//
//  Created by Abhishek More on 2/20/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit

class RightScreenViewController: UIViewController, UICollectionViewDelegate, UICollectionViewDataSource {

    @IBOutlet weak var collectionView: UICollectionView!
    @IBOutlet weak var topRect: UIImageView!
    var collectionViewCenter: CGFloat!
    var topRectCenter: CGFloat!
    
    var selectionArr = [false, false, false]
    
    override func viewDidLoad() {
        super.viewDidLoad()

        collectionViewCenter = collectionView.center.y
        topRectCenter = topRect.center.y
        
    }
    
    func swipeReaction(num: Double) {
        
        collectionView.alpha = CGFloat(abs(1 - num / 125))
        collectionView.center.y = collectionViewCenter + CGFloat(500 * abs(((num - 750) / 375)))
        topRect.center.y = topRectCenter - CGFloat(75 * abs(((num - 750) / 375)))
    }
    
    // MARK: UICollectionView
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 3
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let n = String(indexPath.row + 1)
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: n, for: indexPath)
        var buttonLabel: UILabel!
        var buttonImage: UIImageView!
        for subview in cell.contentView.subviews {
            if subview.tag == 1 {
                buttonImage = subview as? UIImageView
            } else if subview.tag == 2 {
                buttonLabel = subview as? UILabel
            }
        }
        if selectionArr[indexPath.row] {
            buttonLabel.text = "Entered"
            buttonImage.alpha = 0.3
        } else {
            buttonLabel.text = "Join"
            buttonImage.alpha = 0.6
        }
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        selectionArr[indexPath.row] = true
        collectionView.reloadData()
    }
}
