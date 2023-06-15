using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    // Start is called before the first frame update

    bool plantSpell = false, fireSpell = false, iceSpell = false, lightSpell = false;
    GameObject fireObj, iceObj, plantObj, lightObj;
    [SerializeField] GameObject fractalPrefab, flowerPrefab, waterPrefab, bonfirePrefab, firePrefab, icePrefab, plantPrefab, lightPrefab;
    void Start()
    {
        fireObj = GameObject.Find("FireSpell");
        iceObj = GameObject.Find("IceSpell");
        plantObj = GameObject.Find("PlantSpell");
        lightObj = GameObject.Find("LightSpell");

    }

    // Update is called once per frame
    void Update()
    {

    }

    public void FireSpellStatus(bool status)
    {
        fireSpell = status;
        Debug.Log("Fire Spell Status: " + fireSpell);
        Effects();

    }

    public void IceSpellStatus(bool status)
    {
        iceSpell = status;
        Debug.Log("Ice Spell Status: " + iceSpell);
        Effects();
    }

    public void LightSpellStatus(bool status)
    {
        lightSpell = status;
        Debug.Log("Light Spell Status: " + lightSpell);
        Effects();
    }

    public void PlantSpellStatus(bool status)
    {
        plantSpell = status;
        Debug.Log("Plant Spell Status: " + plantSpell);
        Effects();
    }

    void Effects()
    {
        if (fireSpell && iceSpell)
        {
            iceObj.GetComponent<PrefabInstantiator>().ChangePrefab(waterPrefab);
            Debug.Log("Water Casted");
        }
        if (iceSpell && lightSpell)
        {
            iceObj.GetComponent<PrefabInstantiator>().ChangePrefab(fractalPrefab);
            Debug.Log("Fractal Casted");
        }
        if(lightSpell && plantSpell)
        {
            plantObj.GetComponent<PrefabInstantiator>().ChangePrefab(flowerPrefab);
            Debug.Log("Flower Casted");
        }
        if(plantSpell && fireSpell)
        {
            plantObj.GetComponent<PrefabInstantiator>().ChangePrefab(bonfirePrefab);
            Debug.Log("Bonfire Casted");
        }
        else if (plantSpell)
        {
            plantObj.GetComponent<PrefabInstantiator>().ChangePrefab(plantPrefab);
        }
        else if (iceSpell)
        {
            iceObj.GetComponent<PrefabInstantiator>().ChangePrefab(icePrefab);
        }
    }
}
