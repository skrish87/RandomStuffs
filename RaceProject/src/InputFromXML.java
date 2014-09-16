import java.util.*;
import java.io.*;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.DOMException;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class InputFromXML extends RaceImpl  
{
	Runner r = null;
	ArrayList<Runner> Runners = new ArrayList<>();
	        
    public InputFromXML(String fileName)
    {
    	super(fileName);
    }
    
	public ArrayList<Runner> getRunners() throws NumberFormatException, FileNotFoundException, DOMException 
    {
		if (checkFileExists()) {
			try {
					//Read XML file for the input using DOM parser
					DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
					DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
					Document doc = dBuilder.parse(inputFile);
					System.out.println("Root element :"+ doc.getDocumentElement().getNodeName());
					NodeList nList = doc.getElementsByTagName("Runner");
					for (int temp = 0; temp < nList.getLength(); temp++) 
					{
						Node nNode = nList.item(temp);

						System.out.println("\nCurrent Element: " + nNode.getNodeName());

						if (nNode.getNodeType() == Node.ELEMENT_NODE) {

							Element eElement = (Element) nNode;
							String name = eElement.getAttribute("Name");
							System.out.println("Name: " + name);

							String runnerrSpeed = eElement
									.getElementsByTagName("RunnersMoveIncrement")
									.item(0).getTextContent();

							String runnerRest = eElement
									.getElementsByTagName("RestPercentage").item(0)
									.getTextContent();

							int speed = Integer.parseInt(runnerrSpeed);						
							int rest = Integer.parseInt(runnerRest);						

							r = new Runner(name, speed, rest);
							Runners.add(r);
						}
				}				
			} catch (IOException | ParserConfigurationException | SAXException e) {
				System.out.println(e);
				return null;
			}
		}
		return Runners;
    }

	public Runner getRunner(String r) {
		// TODO Auto-generated method stub
		return null;
	}

	




}