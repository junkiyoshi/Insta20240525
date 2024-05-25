#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 50, true, true, true);
	//this->word = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	this->word = "0123456789";
}

//--------------------------------------------------------------
void ofApp::update() {


}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSeedRandom(39);

	for (int i = 0; i < 350; i++) {

		auto x = ofRandom(0, ofGetWindowWidth());
		auto y = int(ofRandom(1000) + ofGetFrameNum() * ofRandom(5, 11)) % 1000 - 200;
		auto location = glm::vec2(x, y);

		ofPushMatrix();
		ofTranslate(location);
		ofRotate(ofRandom(360));

		ofPath chara_path = this->font.getCharacterAsPoints(this->word[(int)ofRandom(this->word.size())], true, false);
		vector<ofPolyline> outline = chara_path.getOutline();

		ofNoFill();
		ofSetColor(255, 0, 0);
		ofBeginShape();
		for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

			ofNextContour(true);

			auto vertices = outline[outline_index].getVertices();
			for (auto& vertex : vertices) {

				ofVertex(vertex);
			}
		}
		ofEndShape(true);

		ofPopMatrix();
	}

	ofSeedRandom(39);
	for (int i = 0; i < 350; i++) {

		auto x = ofRandom(0, ofGetWindowWidth());
		auto y = int(ofRandom(1000) + ofGetFrameNum() * ofRandom(5, 11)) % 1000 - 200;
		auto location = glm::vec2(x, y);

		ofPushMatrix();
		ofTranslate(location);
		ofRotate(ofRandom(360));

		ofPath chara_path = this->font.getCharacterAsPoints(this->word[(int)ofRandom(this->word.size())], true, false);
		vector<ofPolyline> outline = chara_path.getOutline();

		ofFill();
		ofSetColor(39);
		ofBeginShape();
		for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

			ofNextContour(true);

			auto vertices = outline[outline_index].getVertices();
			for (auto& vertex : vertices) {

				ofVertex(vertex * 0.99);
			}
		}
		ofEndShape(true);

		ofPopMatrix();
	}

	/*
	int start = 150;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}