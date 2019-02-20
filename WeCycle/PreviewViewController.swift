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

class PreviewViewController: UIViewController {
    


    private var tags: [String]?
    @IBOutlet var cancel: UIButton!
    var image:UIImage?
    var imageData: Data?
    var urlLink: URL?
    @IBOutlet var cancelX: UIImageView!
    @IBOutlet var photo: UIImageView!
    @IBOutlet var TagName: UILabel!
    var tagList: [String] = []
    @IBOutlet var card: UIImageView!
    @IBOutlet var blackView: UIView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        TagName.center.y += 300
        card.center.y += 300
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
    
    func optimizeList() {
        for i in 0...(tagList.count - 3) {
            tagList[i] = tagList[i].capitalizingFirstLetter()
            if tagList[i] == "No person" || tagList[i] == "No person"  {
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
                                self.TagName.text = self.tagList[0]
                                
                                
                                UIView.animate(withDuration: 1) {
                                    self.card.center.y -= 300
                                    self.TagName.center.y -= 300
                                    self.blackView.alpha = 0.5
                                }
                                
                            }  else {
                                
                                self.TagName.text = "invalid"
                                
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
