//
//  CameraViewController.swift
//  UI Animation
//
//  Created by Abhishek More on 2/16/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit
import AVFoundation
import Alamofire

class CameraViewController: UIViewController{

    var shapeLayer = CAShapeLayer()
    var loadLayer = CAShapeLayer()
    var pulsatingLayer: CAShapeLayer!
    var captureSession = AVCaptureSession()
    var backCamera: AVCaptureDevice?
    var frontCamera: AVCaptureDevice?
    var currentCamera: AVCaptureDevice?
    var photoOutput: AVCapturePhotoOutput?
    var cameraPreviewLayer: AVCaptureVideoPreviewLayer?
    var toggleCameraGestureRecognizer = UITapGestureRecognizer()
    var image: UIImage?
    var imageByte: Data?
    @IBOutlet var cameraFrame: UIView!
    @IBOutlet var blackView: UIView!
    @IBOutlet var shutterFrame: UIButton!
    @IBOutlet var blueBlur: UIImageView!
    @IBOutlet var blue: UIVisualEffectView!
    
    override func viewDidLoad() {
        
        super.viewDidLoad()
        
        self.shutterFrame.alpha = 0
        
        setUpCaptureSession()
        setUpDevice()
        setUpInputOutput()
        setUpPreviewLayer()
        startRunningCaptureSession()
        
        blackView.alpha = 1 
        toggleCameraGestureRecognizer.numberOfTapsRequired = 2
        toggleCameraGestureRecognizer.addTarget(self, action: #selector(toggleCamera))
        view.addGestureRecognizer(toggleCameraGestureRecognizer)
        
        let center = self.shutterFrame.center
        
    
//        let trackLayer = CAShapeLayer()
//
//        let circularPath = UIBezierPath(arcCenter: center, radius: 37.5, startAngle: -CGFloat.pi / 2,   endAngle: 2 * CGFloat.pi, clockwise: true)
//        trackLayer.path = circularPath.cgPath
//
//        trackLayer.strokeColor = UIColor.white.cgColor
//        trackLayer.lineWidth = 5
//        trackLayer.fillColor = UIColor.clear.cgColor
//        trackLayer.lineCap = CAShapeLayerLineCap.round
//        view.layer.addSublayer(trackLayer)
        
        let circularPath2 = UIBezierPath(arcCenter: center, radius: 38.05, startAngle: -CGFloat.pi / 2, endAngle: 2 * CGFloat.pi, clockwise: true)
        shapeLayer.path = circularPath2.cgPath

        shapeLayer.strokeColor = UIColor.white.cgColor
        shapeLayer.lineWidth = 0
        shapeLayer.fillColor = UIColor.clear.cgColor
        shapeLayer.lineCap = CAShapeLayerLineCap.round
        shapeLayer.opacity = 0.35

        view.layer.addSublayer(shapeLayer)
    }

    override func viewDidAppear(_ animated: Bool) {
        UIView.animate(withDuration: 0.25) {
            self.blackView.alpha = 0
        }

        pulseAnimation()
        
    }
    
    func pulseAnimation() {
        
        let basicAnimation = CABasicAnimation(keyPath: "lineWidth")
        
        basicAnimation.toValue = 14.5
        
        basicAnimation.duration = 1
        basicAnimation.autoreverses = true
        basicAnimation.repeatCount = Float.infinity
        basicAnimation.fillMode = CAMediaTimingFillMode.forwards
        basicAnimation.isRemovedOnCompletion = false
        
        shapeLayer.add(basicAnimation, forKey: "urSoBasic")
    }

    
    func setUpCaptureSession() {
        
        captureSession.sessionPreset = AVCaptureSession.Preset.hd1920x1080
        
    }
    
    func setUpDevice() {
        
        let deviceDiscoverySession = AVCaptureDevice.DiscoverySession(deviceTypes: [AVCaptureDevice.DeviceType.builtInWideAngleCamera], mediaType: AVMediaType.video, position: AVCaptureDevice.Position.unspecified)
        let devices = deviceDiscoverySession.devices
        
        for device in devices {
            
            if device.position == AVCaptureDevice.Position.back {
                backCamera = device
            }
            else if device.position == AVCaptureDevice.Position.front {
                frontCamera = device
            }
        }
        
        currentCamera = backCamera
        
    }

    
    
    func setUpInputOutput() {
        do {
            let captureDeviceInput = try AVCaptureDeviceInput(device: currentCamera!)
            captureSession.addInput(captureDeviceInput)
            photoOutput = AVCapturePhotoOutput()
            photoOutput?.setPreparedPhotoSettingsArray([AVCapturePhotoSettings(format: [AVVideoCodecKey: AVVideoCodecType.jpeg])] , completionHandler: nil)
            captureSession.addOutput(photoOutput!)
        } catch {
            print(error)
        }
        
    }
    
    func setUpPreviewLayer() {
        

        cameraPreviewLayer = AVCaptureVideoPreviewLayer(session: captureSession)
        cameraPreviewLayer?.videoGravity = AVLayerVideoGravity.resizeAspectFill
        cameraPreviewLayer?.connection?.videoOrientation = AVCaptureVideoOrientation.portrait
        
        cameraPreviewLayer?.frame = blackView.frame
        self.view.layer.insertSublayer(cameraPreviewLayer!, at: 0)
        
    }
    
    func startRunningCaptureSession() {
        
        captureSession.startRunning()
        
    }
    
     @objc private func toggleCamera() {
        captureSession.beginConfiguration()
        
        // Change the device based on the current camera
        let newDevice = (currentCamera?.position == AVCaptureDevice.Position.back) ? frontCamera : backCamera
        
        // Remove all inputs from the session
        for input in captureSession.inputs {
            captureSession.removeInput(input as! AVCaptureDeviceInput)
        }
        
        // Change to the new input
        let cameraInput:AVCaptureDeviceInput
        do {
            cameraInput = try AVCaptureDeviceInput(device: newDevice!)
        } catch {
            print(error)
            return
        }
        
        if captureSession.canAddInput(cameraInput) {
            captureSession.addInput(cameraInput)
        }
        
        currentCamera = newDevice
        captureSession.commitConfiguration()
        
    }
    
    @IBAction func shutterTouched(_ sender: Any) {
        
        pulseClose()
        
    }
    
    @IBAction func shutterDrag(_ sender: Any) {
        
        pulseAnimation()
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.15) {
            self.shapeLayer.removeAllAnimations()
            
        }
        
    }
    
    @IBAction func shutterRelease(_ sender: Any) {
        
        let settings = AVCapturePhotoSettings()
        self.photoOutput?.capturePhoto(with: settings, delegate: self)

    }
    
    func blurring(num: Double) {
        
        self.blueBlur.alpha = CGFloat(abs(375.0 - num) / 250)
        self.shapeLayer.opacity = Float(CGFloat(0.3 - abs(375.0 - num) / 25))
        //self.blueBlur.alpha = CGFloat(abs(375.0 - num) / 750)
        
    }
    
    func pulseClose() {
        
        let reverse = CABasicAnimation(keyPath: "lineWidth")
        reverse.toValue = 0
        
        reverse.duration = 0.15
        reverse.autoreverses = true
        reverse.repeatCount = Float.infinity
        reverse.fillMode = CAMediaTimingFillMode.forwards
        reverse.isRemovedOnCompletion = true
        shapeLayer.add(reverse, forKey: "reverse")
    
    }
    
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "pictureTaken" {
            let previewViewController = segue.destination as! PreviewViewController
            previewViewController.image = self.image
            previewViewController.imageData = self.imageByte
            blackView.alpha = 1
        }
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

extension CameraViewController: AVCapturePhotoCaptureDelegate {
    
    func photoOutput(_ output: AVCapturePhotoOutput, didFinishProcessingPhoto photo: AVCapturePhoto, error: Error?) {
        if let imageData = photo.fileDataRepresentation() {
            self.image = UIImage(data: imageData)
            self.imageByte = imageData as NSData as Data
            performSegue(withIdentifier: "pictureTaken", sender: nil)
            
        }
        
    }}

