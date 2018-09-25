using UnityEngine;
using System.Collections;
using System.Threading;
using System.IO.Ports;

public class NewBehaviourScript : MonoBehaviour {
    public static SerialPort sp = new SerialPort("COM4", 9600);
    public string mensage2;
    // Use this for initialization
    void Start () {
        sp.Open();
        sp.ReadTimeout = 16;
        print("port Opened!");
        
	}

    // Update is called once per frame
    void Update()
    {
        //timePassed+=Time.deltaTime;
        //if(timePassed>=0.2f){

        //print("BytesToRead" +sp.BytesToRead);
        message2 = sp.ReadLine();
        print(message2);
        // timePassed = 0.0f;
        //}
    }

    void OnApplicationQuit()
    {
        sp.Close();
    }

    public static void sendYellow()
    {
        sp.Write("y");
    }

    public static void sendGreen()
    {
        sp.Write("g");
        //sp.Write("\n");
    }

    public static void sendRed()
    {
        sp.Write("r");
    }
}
