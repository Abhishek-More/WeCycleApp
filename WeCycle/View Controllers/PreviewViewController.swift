//
//  PreviewViewController.swift
//  UI Animation
//
//  Created by Abhishek More on 2/16/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit
import AVFoundation
import Alamofire
import Firebase
import SwiftyJSON


class PreviewViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate, UIViewControllerTransitioningDelegate {

    @IBOutlet var collectionView: UICollectionView!
    private var tags: [String]?
    @IBOutlet var cancel: UIButton!
    var image:UIImage?
    var imageData: Data?
    var urlLink: URL?
    @IBOutlet var cancelX: UIImageView!
    @IBOutlet var photo: UIImageView!
    var tagList: [String] = []
    @IBOutlet var blackView: UIView!
    let transition = CircularTransition()
    var lel: Bool = false
    
    @IBOutlet var menuButton: UIButton!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
//        collectionView.center.x += 350
        blackView.alpha = 0
        
        uploadImageToFirebaseStorage(data: imageData! as NSData)
        cancelX.alpha = 0
        cancelX.center.y -= 15

        photo.image = image
        
        // Do any additional setup after loading the view.
    }
    
    override func viewDidAppear(_ animated: Bool) {
        
        UIView.animate(withDuration: 0.5) {
            self.cancelX.center.y += 15
            self.cancelX.alpha = 1
        }
        
    }
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
       
        return tagList.count
        
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Cell", for: indexPath) as! MainCollectionViewCell
        
        cell.tagName.text = tagList[indexPath.item]
        if(lel) {
        cell.recyLabel.textColor = .green
        cell.recyLabel.text = "Recyclable"
        } else {
        cell.recyLabel.textColor = .red
        cell.recyLabel.text = "Not Recyclable"
        }
        
        
        return cell
        
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
    
    func optimizeList() {
        for i in 0...(tagList.count - 3) {
            tagList[i] = tagList[i].capitalizingFirstLetter()
            if tagList[i] == "No person" || tagList[i] == "People"  {
                tagList.remove(at: i)
            }
        }
        
    }
    
    @IBAction func cancelButton(_ sender: Any) {
        
        dismiss(animated: true, completion: nil)
        
    }
    
    @IBAction func useButton(_ sender: Any) {
        
        //send image to firebase
        //retrieve link
        uploadImageToFirebaseStorage(data: imageData! as NSData)
        
    }
    
    func uploadImageToFirebaseStorage(data: NSData) {

        let storageRef = Storage.storage().reference(withPath: "Pictures/DemoPictures.jpg")
        let uploadMetaData = StorageMetadata()
        
        
        uploadMetaData.contentType = "image/jpeg"
        _ = storageRef.putData(data as Data, metadata: uploadMetaData) { (metadata, error) in
            if(error != nil) {
                print("I've recieved an error \(String(describing: error?.localizedDescription))")
            } else {
                print("Upload Complete")
                storageRef.downloadURL { (url, error) in
                    if error != nil {
                        print(error!)
                    } else {
                        print(url!)
                        let urlString = url!.absoluteString
                        let helper = ClarifaiAPIHelper.defaultHelper
                        helper.getTags(url: urlString) { (tags) in
                            if let tags = tags {
                                
                                for tag in tags  {
                                    self.tagList.append(tag.0)
                                }
                                print(self.tagList)
                                self.optimizeList()
                                self.collectionView.reloadData()
                                
//
//                                UIView.animate(withDuration: 1) {
//                                    self.collectionView.center.x -= 350
//                                    self.blackView.alpha = 0.5
//                                }
                                
                            }  else {
                                
                            }
                            
                        }
                        
                    }
                    
                }

            }
            
        }

    }
}


extension String {
    
    func capitalizingFirstLetter() -> String {
        return prefix(1).capitalized + dropFirst()
    }
    
    mutating func capitalizeFirstLetter() {
        self = self.capitalizingFirstLetter()
    }
}
