using UnityEngine;
using Vuforia;

public class PrefabInstantiator : DefaultObserverEventHandler
{
    public GameObject myModelPrefab;
    public float scale = 0.01f;
    public float height = 0.0f;
    public float rotation = 0.0f;
    GameObject mMyModelObject;

    protected override void OnTrackingFound()
    {
        Debug.Log("Target Found");

        // Instantiate the model prefab only if it hasn't been instantiated yet
        if (mMyModelObject == null)
            InstantiatePrefab();

        base.OnTrackingFound();
    }

    void InstantiatePrefab()
    {
        if (myModelPrefab != null)
        {
            Debug.Log("Target found, adding content");
            mMyModelObject = Instantiate(myModelPrefab, mObserverBehaviour.transform);
            mMyModelObject.transform.localScale = Vector3.one * scale;
            mMyModelObject.transform.localPosition = new Vector3(0, height, 0);
            mMyModelObject.transform.localRotation = Quaternion.Euler(0, 0, rotation);
            mMyModelObject.SetActive(true);
            mMyModelObject.GetComponentInChildren<Animator>().enabled = true;
        }
    }

    public void ChangePrefab(GameObject newPrefab)
    {
        myModelPrefab = newPrefab;
        if (mMyModelObject != null)
        {
            Destroy(mMyModelObject);
            mMyModelObject = null;
        }
        InstantiatePrefab();
    }
}